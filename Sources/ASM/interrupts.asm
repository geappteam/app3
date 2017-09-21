
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;; Les directives ;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    .def _enableInterrupts

    .data




    .text


_enableInterrupts
    .asmfunc

	MVC IER, B1
 	MVK 0x12, A1
	OR 	A1, B1, B1 	; NMIE and INT4
	MVC B1, IER

    MVC CSR, B0     ; Get CSR
    OR 1, B0, B0    ; Get ready to clear GIE
    MVC B0, CSR     ; Clear GIE

    B B3 ; INDISPENSABLE ; B3 contient l'adresse de retour
    NOP 5

    .endasmfunc
