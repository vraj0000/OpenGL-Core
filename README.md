graph TD
    %% Styling
    classDef domainA fill:#eef9ff,stroke:#007acc,stroke-width:2px,color:#000;
    classDef domainB fill:#f0fff0,stroke:#28a745,stroke-width:2px,color:#000;
    classDef logic fill:#fff,stroke:#333,stroke-width:1.5px,color:#000;

    subgraph AXI_Stream_Domain ["s_axis_clk Domain"]
        direction LR
        tvalid["s_axis_tvalid"] --> andGate["write_en = tvalid & !wfull"]
        tdata["s_axis_tdata [7:0]"] --> fifo
        wfull_sig["!wfull"] --> tready["s_axis_tready"]
        wfull_sig --> andGate
    end

    subgraph FIFO_Core ["Async FIFO (Clifford Cummings Style)"]
        fifo["async_fifo<br/>(sync_r2w, sync_w2r,<br/>wptr_full, rptr_empty, fifomem)"]
    end

    subgraph UART_Domain ["uart_clk Domain"]
        direction LR
        fifo -->|"async_rdata [7:0]"| uartTx["uart_tx"]
        rempty_sig["!fifo_empty"] --> combLogic["uart_sand = !fifo_empty & !uart_busy"]
        busy_sig["uart_busy"] --> combLogic
        combLogic -->|"send"| uartTx
        uartTx -->|"RsTx"| txd["uart_txd"]
    end

    %% Cross-Domain connections
    andGate -->|"winc (write_en)"| fifo
    combLogic -->|"rinc (uart_sand)"| fifo

    class AXI_Stream_Domain domainA;
    class UART_Domain domainB;
    class fifo,uartTx,combLogic,andGate logic;
