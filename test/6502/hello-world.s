PORTB = $6000
PORTA = $6001
DDRB = $6002
DDRA = $6003

E  = %10000000
RW = %01000000
RS = %00100000

  .org $8000

reset:
  lda #%11111111 ; Set all pins on port B to output
  sta DDRA

  lda #%11100000 ; Set top 3 pins on port A to output
  sta DDRB
loop:
  lda #%00000001 ; Clear Screen
  sta PORTA
  lda #0         ; Clear RS/RW/E bits
  sta PORTB
  lda #E         ; Set E bit to send instruction
  sta PORTB
  lda #0         ; Clear RS/RW/E bits
  sta PORTB

  lda #%00000010 ; Return Home
  sta PORTA
  lda #0         ; Clear RS/RW/E bits
  sta PORTB
  lda #E         ; Set E bit to send instruction
  sta PORTB
  lda #0         ; Clear RS/RW/E bits
  sta PORTB

  lda #%00111000 ; Set 8-bit mode; 2-line display; 5x8 font
  sta PORTA
  lda #0         ; Clear RS/RW/E bits
  sta PORTB
  lda #E         ; Set E bit to send instruction
  sta PORTB
  lda #0         ; Clear RS/RW/E bits
  sta PORTB

  lda #%00001110 ; Display on; cursor on; blink off
  sta PORTA
  lda #0         ; Clear RS/RW/E bits
  sta PORTB
  lda #E         ; Set E bit to send instruction
  sta PORTB
  lda #0         ; Clear RS/RW/E bits
  sta PORTB

  lda #%00000110 ; Increment and shift cursor; don't shift display
  sta PORTA
  lda #0         ; Clear RS/RW/E bits
  sta PORTB
  lda #E         ; Set E bit to send instruction
  sta PORTB
  lda #0         ; Clear RS/RW/E bits
  sta PORTB

  lda #"H"
  sta PORTA
  lda #RS         ; Set RS; Clear RW/E bits
  sta PORTB
  lda #(RS | E)   ; Set E bit to send instruction
  sta PORTB
  lda #RS         ; Clear E bits
  sta PORTB

  lda #"e"
  sta PORTA
  lda #RS         ; Set RS; Clear RW/E bits
  sta PORTB
  lda #(RS | E)   ; Set E bit to send instruction
  sta PORTB
  lda #RS         ; Clear E bits
  sta PORTB

  lda #"l"
  sta PORTA
  lda #RS         ; Set RS; Clear RW/E bits
  sta PORTB
  lda #(RS | E)   ; Set E bit to send instruction
  sta PORTB
  lda #RS         ; Clear E bits
  sta PORTB

  lda #"l"
  sta PORTA
  lda #RS         ; Set RS; Clear RW/E bits
  sta PORTB
  lda #(RS | E)   ; Set E bit to send instruction
  sta PORTB
  lda #RS         ; Clear E bits
  sta PORTB

  lda #"o"
  sta PORTA
  lda #RS         ; Set RS; Clear RW/E bits
  sta PORTB
  lda #(RS | E)   ; Set E bit to send instruction
  sta PORTB
  lda #RS         ; Clear E bits
  sta PORTB

  lda #","
  sta PORTA
  lda #RS         ; Set RS; Clear RW/E bits
  sta PORTB
  lda #(RS | E)   ; Set E bit to send instruction
  sta PORTB
  lda #RS         ; Clear E bits
  sta PORTB

  lda #" "
  sta PORTA
  lda #RS         ; Set RS; Clear RW/E bits
  sta PORTB
  lda #(RS | E)   ; Set E bit to send instruction
  sta PORTB
  lda #RS         ; Clear E bits
  sta PORTB

  lda #"W"
  sta PORTA
  lda #RS         ; Set RS; Clear RW/E bits
  sta PORTB
  lda #(RS | E)   ; Set E bit to send instruction
  sta PORTB
  lda #RS         ; Clear E bits
  sta PORTB

  lda #"o"
  sta PORTA
  lda #RS         ; Set RS; Clear RW/E bits
  sta PORTB
  lda #(RS | E)   ; Set E bit to send instruction
  sta PORTB
  lda #RS         ; Clear E bits
  sta PORTB

  lda #"r"
  sta PORTA
  lda #RS         ; Set RS; Clear RW/E bits
  sta PORTB
  lda #(RS | E)   ; Set E bit to send instruction
  sta PORTB
  lda #RS         ; Clear E bits
  sta PORTB

  lda #"l"
  sta PORTA
  lda #RS         ; Set RS; Clear RW/E bits
  sta PORTB
  lda #(RS | E)   ; Set E bit to send instruction
  sta PORTB
  lda #RS         ; Clear E bits
  sta PORTB

  lda #"d"
  sta PORTA
  lda #RS         ; Set RS; Clear RW/E bits
  sta PORTB
  lda #(RS | E)   ; Set E bit to send instruction
  sta PORTB
  lda #RS         ; Clear E bits
  sta PORTB

  lda #"!"
  sta PORTA
  lda #RS         ; Set RS; Clear RW/E bits
  sta PORTB
  lda #(RS | E)   ; Set E bit to send instruction
  sta PORTB
  lda #RS         ; Clear E bits
  sta PORTB

	;loop:
  jmp loop

  .org $fffc
  .word reset
  .word $0000
