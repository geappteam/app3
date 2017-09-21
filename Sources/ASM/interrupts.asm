
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;; Les directives ;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    .def _enableInterrupts
    .def _setInterrupt

    .data




    .text


_enableInterrupts
    .asmfunc

	MVC IER, B1
 	MVK 0x2, A1
	OR 	A1, B1, B1 	; NMIE
	MVC B1, IER

    MVC CSR, B0     ; Get CSR
    OR 1, B0, B0    ; Get ready to clear GIE
    MVC B0, CSR     ; Clear GIE

    B B3 ; INDISPENSABLE ; B3 contient l'adresse de retour
    NOP 5

    .endasmfunc


; (interuptSelect, ON / OFF)
_setInterrupt
    .asmfunc

	CMPGT A4, 15, B0
	CMPGT 4, A4, B1
	OR B0, B1, B0
	[B0] B B3
	NOP 5

	MV B4, A1
	MVC IER, B1
 	MVK 1, A2
 	SHL A2, A4, A2
	[A1] B TurnOn
	NOP 5

TurnOff:

	NOT A2, A2
	AND	A2, B1, B1
	MVC B1, IER
	B B3
	NOP 5

TurnOn:

	OR 	A2, B1, B1
	MVC B1, IER

    B B3 ; INDISPENSABLE ; B3 contient l'adresse de retour
    NOP 5

    .endasmfunc
