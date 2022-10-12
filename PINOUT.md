                          +-----+
             +------------| USB |------------+
             |            +-----+            |
             | [ ]D13/SCK        MISO/D12[ ] |
             | [ ]3.3V           MOSI/D11[ ]~|
             | [ ]V.ref     ___    SS/D10[ ]~|
             | [ ]A0       / N \       D9[X]~| RED BUTTON
             | [ ]A1      /  A  \      D8[X] | BLUE BUTTON
             | [ ]A2      \  N  /      D7[ ] |
             | [ ]A3       \_0_/       D6[ ]~|
    LCD KPAD | [X]A4/SDA               D5[X]~| DIO 7SEGMENT
    LCD KPAD | [X]A5/SCL               D4[X] | CLK 7SEGMENT
             | [ ]A6              INT1/D3[ ]~| 
             | [ ]A7              INT0/D2[ ] |   
             | [ ]5V                  GND[ ] |     
             | [ ]RST                 RST[ ] |   
             | [ ]GND   5V MOSI GND   RX1[ ] |   
             | [ ]Vin   [ ] [ ] [ ]   TX1[ ] |   
             |          [ ] [ ] [ ]          |
             |          MISO SCK RST         |
             | NANO-V3                       |
             +-------------------------------+