# University OOP — Defense Notes

> Sir final project e **deeply question** korben. Ei file e protita topic er
> "ki" ar **"keno"** — duita-i thakbe. Mukhosto na, bujhe bolte hobe.
>
> Job-prep er notes alada: `../NOTES.md`

---

## 01 — OOP Basics

**Q: OOP ki? Procedural er theke ki alada?**
Procedural e data ek jaygay, function onno jaygay — kono somporko nai, jekeu jekono data bodlate pare। OOP e **data ar tar upor er kaj ek boksho te (object)**, ar vitor ta lukano।

**Q: Class ar Object er difference?**
Class = **nokša** (blueprint), memory ney na। Object = oi nokša theke banano asol jinish, memory ney। Ek nokša theke joto khushi object। Object ke **instance** o bole।

**Q: Char ta stombho?**
1. **Encapsulation** — data private, public function diye niyontrito access
2. **Inheritance** — child parent er jinish uttoradhikar sutre pay
3. **Polymorphism** — ek naam, alada achoron
4. **Abstraction** — joṭilota lukiye shudhu dorkari ongsho dekhano

**Q: Encapsulation ar Abstraction er difference? (sir dhorben)**
| | Encapsulation | Abstraction |
|---|---|---|
| Ki lukay | **data** | **joṭilota / bastobayon** |
| Prosno | "ke chute parbe?" | "ki dekhano dorkar?" |
| Kivabe | `private` + getter/setter | abstract class, interface |

Gari: tel er tank bondho (encapsulation) · accelerator chapo, engine e ki hoy jano na (abstraction)।

**Q: Member function er vitore `model` likhle kar model?**
Je object er upor daka hoyeche, tar। `r15.callKoro()` e `model` mane `r15.model`. Vitore vitore C++ ekta lukano pointer `this` pathay — `model` asole `this->model`.

---

## 02 — Inheritance

**Q: Inheritance ki? Kokhon use korbe?**
Ekta class onno class er member uttoradhikar sutre pay — code duplication kome ar hierarchy toiri hoy।
**Porikkha — "is-a" test:** "Car IS-A Vehicle?" ha ✅ → inheritance। "Engine IS-A Vehicle?" na, engine vehicle er **ongsho** → composition, inheritance na।

**Q: Syntax?**
```cpp
class Sportsbike : public Vehicle
{
public:
    Sportsbike(string m, double p, int cc)
        : Vehicle(m, p)      // ← parent er constructor AGE
    { engineCC = cc; }
};
```

**Q: Constructor er order?**
**Parent er constructor age chole, tarpor child er।** Karon child er kaj korar age parent er ongsho toiri thakte hobe। Destructor er order **ulta** — child age, parent pore।

**Q: `private` ar `protected` er difference?**
| | Class er vitore | Child e | Bahire |
|---|---|---|---|
| `private` | ✅ | ❌ | ❌ |
| `protected` | ✅ | ✅ | ❌ |
| `public` | ✅ | ✅ | ✅ |

`protected` = "chele-meye dekhbe, bahirer keu na"। Child jokhon parent er data **shorasori** chute chay tokhon lagey। Na chulei `private` rakha bhalo (beshi nirapod)।

**Q: Child e parent er ek naam er variable likhle?**
**Shadowing** — duita alada boksho toiri hoy, ek-i naam। Child nijer ta dekhe, parent er function parent er ta dekhe → ekta bodlale onnota purono thake → **bug**। `protected` diye parent er ta-i share kora uchit।

**Q: Method Overriding ki? Overloading er theke alada?**
| | Overloading | Overriding |
|---|---|---|
| Kothay | **ek-i** class e | parent ar child e |
| Ki alada | **parameter** alada | signature **hubohu ek** |

Child er version parent er ta **dheke dey**। Jor kore parent er ta dakte: `obj.Vehicle::callKoro();`

---

## 03 — Polymorphism & `virtual` ⭐ (sir er 1 nombor prosno)

**Q: Virtual function ki? Na dile ki hoy?**
`virtual` **na** dile C++ pointer/reference er **declared type** dekhe sidhanto ney (**static binding**) — tai `Vehicle* v = &sportsbike; v->callKoro();` dakle **Vehicle er version** chole, child er override kaj kore na।
`virtual` dile runtime e **asol object** er type dekhe sidhanto hoy (**dynamic binding**) — ei ta-i **runtime polymorphism**।

```cpp
class Vehicle    { public: virtual void callKoro() { ... } };
class Sportsbike : public Vehicle { public: void callKoro() override { ... } };

Vehicle* v = &r15;
v->callKoro();      // virtual thakle Sportsbike er, na thakle Vehicle er
```

**Q: Vitore vitore kivabe kaj kore?**
Protita polymorphic class er ekta **vtable** (virtual function table) thake — oi class er virtual function gulor thikanar table। Protita object e ekta lukano **vptr** thake ja oi table ke dekhay। Call er shomoy vptr → vtable → thik function.

**Q: `override` keyword keno?**
Compiler ke bolo "ami jene shune override korchi"। Signature bhul hole (typo, alada parameter) compiler **error dibe** — na hole chup-chap ekta notun function toiri hoye jeto ar bug hoto।

**Q: Polymorphism keno dorkar?**
```cpp
for (Vehicle* v : inventory) { v->callKoro(); }
```
Ek-i code, protita object nijer moto behave kore। `if (type == "bike") ... else if (type == "car")` — ei rokom type-check er sarni lage na। Notun vehicle type add korle ei loop e **hat dite hoy na** (Open/Closed principle — SOLID)।

---

## Baki topic gulo ashbe jokhon shikhbo.

