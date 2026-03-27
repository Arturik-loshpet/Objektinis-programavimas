Kaip naudotis programa:

1. make - komanda sukuria failą "programa" pagal makefile.
2. ./programa - komanda paleidžia pačią programą.
3. make clean - išvalyti kompiliacijos failus.



V0.4 testavimai
---------------------------------------------------------------------------------------------------------------------------
4 versijoj duomenų įvedimo sistemoj buvo pridėta nauja failų generavimo funkcija, kuri kuria failus pagal šablonus naudotis 2 versijoj.
Buvo atlikti testavimai laiko apskaičiavimui ir jų rezultatai bus pateikti žemiau:
1 testavimas:
<img width="297" height="93" alt="image" src="https://github.com/user-attachments/assets/a4b163e2-c4dc-4828-9c7c-f11913244bcb" />
<img width="311" height="91" alt="image" src="https://github.com/user-attachments/assets/93e67fd5-3f19-46ca-af49-859e1e848539" />
<img width="287" height="88" alt="image" src="https://github.com/user-attachments/assets/efcb0d4e-a641-4178-9e91-a42b59452283" />
Duoti testavimai turi skirtingus studentų pažymių kiekius, kad matytusi skirtumas tarp atlikimo laikų.

2 testavimas (visi testai buvo atlikti su pažymių sk. = 2 ir rušiuoti pagal medianą):
<img width="983" height="113" alt="image" src="https://github.com/user-attachments/assets/c6d33f22-3fb2-48fc-9228-417cba96252c" />
<img width="990" height="125" alt="image" src="https://github.com/user-attachments/assets/bdd2429a-6c7d-443d-9119-a32dadcf3611" />
<img width="995" height="430" alt="image" src="https://github.com/user-attachments/assets/ce9be59f-902c-4377-b3e0-3a3fcb25d8ac" />

---------------------------------------------------------------------------------------------------------------------------

V1.0 testavimai
Sistema:
CPU - Apple M2 (8 branduoliai)
RAM - 16gb
SSD - 256gb

---------------------------------------------------------------------------------------------------------------------------
1 strategija - Duomenys nuskaitomi į vieną duomenų konteinerį ir skirstymo metu masyvas skirstomas į maladiec ir lopų konteinerius. Rezultatai:
<img width="263" height="115" alt="image" src="https://github.com/user-attachments/assets/f6e62620-45e5-4b27-b60b-fa17550ec58d" />
<img width="261" height="114" alt="image" src="https://github.com/user-attachments/assets/b83a9542-606f-486c-ad91-20d4298a3cab" />
<img width="274" height="113" alt="image" src="https://github.com/user-attachments/assets/d8cc7499-d15c-4398-9390-87656e3f44de" />

---------------------------------------------------------------------------------------------------------------------------
2 strategija - Duomenys nuskaitomi į "maladiec" konteinerį ir žmones su mažesniu vidurkiu yra įdedami i lopai konteineri ir iškerpami. Rezultatai:

<img width="295" height="128" alt="image" src="https://github.com/user-attachments/assets/21024da6-700e-49ee-8348-6dff6948ed25" />
<img width="293" height="126" alt="image" src="https://github.com/user-attachments/assets/c8aa9300-b11c-4423-a82a-eeaf6c0d1977" />
<img width="293" height="129" alt="image" src="https://github.com/user-attachments/assets/ac03cc82-2d30-4901-b502-d864aea7ea9a" />

---------------------------------------------------------------------------------------------------------------------------
3 strategija - Padaryta pagal 2 strategija, tik vietoj erase yra naudojamas prtition algoritmas. Rezultatai:

<img width="258" height="115" alt="image" src="https://github.com/user-attachments/assets/fe110d55-aecd-4e4b-8f18-6f813f41548b" />
<img width="261" height="112" alt="image" src="https://github.com/user-attachments/assets/2559908b-b7ea-4c22-9320-030cf8aed6b0" />
<img width="263" height="115" alt="image" src="https://github.com/user-attachments/assets/b9e15a0c-a37b-4755-8acc-61c29c43b773" />

---------------------------------------------------------------------------------------------------------------------------









