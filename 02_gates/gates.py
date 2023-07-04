import numpy as np


def and_gate(x1, x2):
    x = np.array([x1, x2])  # input
    w = np.array([0.5, 0.5])  # weight
    b = -0.7  # bias
    tmp = np.sum(w * x) + b

    if tmp <= 0:
        return 0
    else:
        return 1


def nand_gate(x1, x2):
    x = np.array([x1, x2])  # input
    w = np.array([-0.5, -0.5])  # weight
    b = 0.7  # bias
    tmp = np.sum(w * x) + b

    if tmp <= 0:
        return 0
    else:
        return 1


def or_gate(x1, x2):
    x = np.array([x1, x2])  # input
    w = np.array([0.5, 0.5])  # weight
    b = -0.2  # bias
    tmp = np.sum(w * x) + b
    if tmp <= 0:
        return 0
    else:
        return 1


def xor_gate(x1, x2):
    s1 = nand_gate(x1, x2)
    s2 = or_gate(x1, x2)
    y = and_gate(s1, s2)
    return y

print("[python implementation of gates]\n")

print("= and gate =")
print(f"0 and 0 = {and_gate(0, 0)}")
print(f"1 and 0 = {and_gate(1, 0)}")
print(f"0 and 1 = {and_gate(0, 1)}")
print(f"1 and 1 = {and_gate(1, 1)}")

print("\n= nand gate =")
print(f"0 nand 0 = {nand_gate(0, 0)}")
print(f"1 nand 0 = {nand_gate(1, 0)}")
print(f"0 nand 1 = {nand_gate(0, 1)}")
print(f"1 nand 1 = {nand_gate(1, 1)}")

print("\n= or gate =")
print(f"0 or 0 = {or_gate(0, 0)}")
print(f"1 or 0 = {or_gate(1, 0)}")
print(f"0 or 1 = {or_gate(0, 1)}")
print(f"1 or 1 = {or_gate(1, 1)}")

print("\n= xor gate =")
print(f"0 xor 0 = {xor_gate(0, 0)}")
print(f"1 xor 0 = {xor_gate(1, 0)}")
print(f"0 xor 1 = {xor_gate(0, 1)}")
print(f"1 xor 1 = {xor_gate(1, 1)}")
