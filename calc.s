.syntax unified
.cpu cortex-m4
.fpu fpv4-sp-d16
.arch armv7e-m

.section .text
.global CalcZ_

CalcZ_:
    push {r4-r9, lr}
    mov r4, #0
    cmp r3, #0
    ble Done
    ldr r5, =g_Val1
    ldr r5, [r5]
    ldr r6, =g_Val2
    ldr r6, [r6]
Loop1:
    ldrsb r7, [r1], #1
    ldrsh r8, [r2], #2
    cmp r7, #0
    it lt
    mullt r9, r8, r5
    it ge
    mulge r9, r8, r6
    add r4, r4, r9
    str r9, [r0], #4
    subs r3, r3, #1
    bne Loop1
Done:
    mov r0, r4
    pop {r4-r9, pc}
	bx lr
