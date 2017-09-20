

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;; Les directives ;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    .def _enableInterrupts

    .data




    .text


_enableInterrupts
    .asmfunc

    MVC CSR, B0     ; Get CSR
    OR 1, B0, B0    ; Get ready to clear GIE
    MVC B0, CSR     ; Clear GIE

    B B3 ; INDISPENSABLE ; B3 contient l'adresse de retour
    NOP 5

    .endasmfunc
