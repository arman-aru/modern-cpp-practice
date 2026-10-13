# C++ Notes — Interview Answers

> Ei file e protita topic er **mukhe bolar moto** answer thakbe.
> Keu jiggesh korle ekhan theke bolte parba. Mukhosto na — bujhe bolo.

---

## 01 — Hello World / Program Structure

**Q: `#include <iostream>` ki kore?**
Eta C++ code na — preprocessor er instruction, compile er **ager** step. Preprocessor `iostream` file er pura content amar file e literally copy-paste kore dey. Tai sheshe `;` nai. `cout`/`cin` er definition oi file e ache, tai na dile compiler `cout` chene na.

**Q: `<>` ar `""` er difference?**
`<>` → system include path e khoje. `""` → age current folder e khoje, na pele system path e jay.

**Q: `using namespace std;` ki kore? Eta kharap keno?**
`std` namespace er shob naam global scope e niye ashe, tai `std::cout` er bodole `cout` likha jay. Kharap karon `std` e hazar hazar naam ache — amar nijer naam er sathe collision hote pare. Header file e dile aro kharap, jara oi header include kore shobai bhogey. Better: `std::` explicitly likha, ba `using std::cout;` (selective).

**Q: `int main()` er `int` keno?**
`main` er return type. Program sesh e OS ke ekta integer ferot dey — **exit code**. `0` = success, non-zero = error. Terminal e `./main && echo ok` er `&&` ei exit code dekhei sidhanto ney.

**Q: `main` e `return 0;` na likhle?**
Compiler nije add kore dey — eta **shudhu `main` er jonno** special. Onno kono non-void function e return na korle undefined behavior.

**Q: C++ e statement kivabe sesh hoy?**
`;` diye. Newline er kono vumika nai — compiler er kache whitespace ortho-hin (string er vitore chara). Tai ekta `cout` ke koyek line e vanga jay.

---

## 02 — Variables

**Q: `=` ar `==` er difference?**
`=` assignment — "daan pash er value bam pashe rakho". `==` comparison — "duita soman ki na" jiggesh kore, uttor true/false.

**Q: `age = age + 5;` kivabe kaj kore?**
Age **daan pash** hishab hoy (purono value pore), tarpor result bam pashe lekha hoy. Math er somikoron na, ekta kaj.

**Q: `age++` ar `++age` er difference?**
`age++` (post) — purono value ta dey, tarpor bariye. `++age` (pre) — age bariye, tarpor notun value dey. Alada line e likhle difference nai; expression er vitore thakle ache.
```cpp
int a = 5; cout << a++;   // 5 chape, a hoy 6
int b = 5; cout << ++b;   // b hoy 6, 6 chape
```

**Q: Variable keno use korbo, direct number likhle ki somossa?**
Single source of truth. Ek jaygay bodlalei shob jaygay bodlay. Hat e likhle ekta jayga bodlate bhule gele **chup-chap bhul answer** ashbe — program error dibe na, ar ei rokom bug dhora sobcheye kothin.

---

## 03 — Input (cin)

**Q: `cout` ar `cin` er difference?**
`cout << x` → x screen e jay (bahire). `cin >> x` → keyboard theke x er vitore ashe। Tir chinho data er jaowar dik dekhay. `cin` er line e program theme opekkha kore, user Enter chapar por chole.

**Q: Uninitialized variable use korle ki hoy?**
Undefined behavior. `int x;` likhle RAM e 4 byte dokhol hoy kintu **porishkar hoy na** — age er program er garbage pore thake. Tai `x` e elomelo number thake, protibar alada hote pare. Amar khetre `garbage + garbage = 48581249` eshechilo. Somadhan: declare korar somoy-i initialize (`int x = 0;`) ar `-Wall` diye compile kora — clang `warning: variable is uninitialized when used here` diye dhore fele.

**Q: Ei code e ki somossa?**
```cpp
int a, b;
int sum = a + b;    // ← ekhane jog hoye gelo (garbage)
cin >> a >> b;      // ← value pore ashlo, DERI
```
Computer upor theke niche **ekbar** kore chole. `sum` er line ekbar-i cholе, tokhon ja chilo tai niyeche. Pore `a`/`b` bodlale `sum` **nije update hoy na** — CSS variable er moto live binding nai. Niyom: **age value dao, tarpor use koro**.

**Q: `error: use of undeclared identifier 'sum'` — keno ashe?**
Tin ta karon: (1) variable ta banao-i nai, (2) banaycho kintu **use korar pore** — computer upor theke niche pore, tai jonmo agey hote hobe, (3) naam e typo (`sum` vs `Sum` — C++ case-sensitive).

**Q: Naming convention?**
`camelCase` — `chipsDam`, `totalBill`, `userAge`. Naam dekhe bojha jabe ki ache — `x`, `a`, `temp` eriye chola. Lomba naam kharap na; self-documenting code mane naam eto sposto je comment lage na. Code review e sobcheye beshi comment ashe naming niye.

**Q: `cin >> a >> b;` ar alada duita `cin` — kon ta kobe?**
Chaining chhoto, kintu ekta-i prompt er por duita number ney. Protita input er alada label/prompt chaile alada line e likhte hoy — HTML e protita `<input>` er nijer `<label>` dewar moto.

---

## 04 — Data Types

**Q: Type keno dorkar?**
Variable RAM e jayga ney. Computer ke agei jante hobe (1) koto byte lagbe, (2) oi bit gulo kon niyome porte hobe. Ek-i bit pattern alada niyome porle alada mane।

| Type | Ki rakhe | Jayga | Khali value |
|---|---|---|---|
| `int` | purno shongkha | 4 byte | `0` |
| `double` | doshomik | 8 byte | `0.0` |
| `char` | **ekta** akkhor | 1 byte | `' '` |
| `bool` | true/false | 1 byte | `false` |
| `string` | onek akkhor | poribortonshil | `""` |

`char` = single quote `'A'`, `string` = double quote `"Arman"`. `string` er jonno `#include <string>`.

**Q: `int` e 20.50 dile ki hoy?**
`.50` ta **chup-chap kete jay**, error dey na — `20` hoye jay. Ei rokom nirob bhul sobcheye bipojjonok।

**Q: `int` er limit koto? Overflow hole?**
4 byte = ±2,147,483,647 (≈2.1×10⁹)। Beshi hole **overflow** — number ulte giye negative hoy (odometer ghurar moto)। LeetCode e "logic thik kintu answer bhul" er sobcheye common karon। Boro number lagle `long long` (±9.2×10¹⁸)।

**Q: `0.1 + 0.2 == 0.3` keno false?**
Computer binary te kaj kore, 0.1 binary te **thik thik** rakha jay na (1/3 ke doshomik e likhar moto — sesh hoy na)। Tai 0.1+0.2 = 0.30000000000000004। Niyom: `double` `==` diye milabe na, `abs(a-b) < 1e-9` dekho।

**Q: `7 / 2` = 3 keno?**
Duita `int` er bhag → result o `int`, doshomik kete jay। `7 / 2.0` dile 3.5 — ekta operand `double` hole pura expression `double` e promote hoy।

**Q: `char` ki asole number?**
Ha, chhoto integer। `'A'`=65, `'a'`=97, `'0'`=48 (ASCII)। Tai `'7' - '0'` = 7 — akkhor ke digit banano trick, LeetCode e prochur lagey।

**Q: `cout << true` e ki ashe?**
`1`, "true" na। `bool` ke `cout` number hishebe dekhay। `true`/`false` lekha chaile `cout << boolalpha`।

**Q: `3.40` print korle `3.4` ashe keno? Fix?**
`3.40` ar `3.4` ek-i number — sheshe zero kono tottho boy na। `cout` default e onaboshyok zero fele dey। Fix: `#include <iomanip>` + `cout << fixed << setprecision(2);` — ekbar dile er por theke shob `double` 2 ghor e dekhabe।

**Q: `char grade` e `A+` dile ki hoy?**
Shudhu `A` ney — `char` thik ekta akkhor rakhe। `+` buffer e pore thake। `A+`/`B-` lagle type-i bhul, `string` lagbe।

**Q: `cin >>` ar `getline` er difference?**
`cin >>` whitespace e thame — ek shobdo ney, newline ta buffer e rekhe dey। `getline(cin, s)` pura line ney (space shoho) ar newline ta khaye fele। `cin >>` er pore `getline` dile purono newline ta dhore khali string pay — majhe `cin.ignore()` lagey।

**Q: "Aman Salek" dile pura program keno ultapalta hoy?**
Keyboard er lekha age **buffer** e jome। `cin >> nam` space porjonto niye `Aman` nilo, `Salek` buffer e roye gelo। Porer `cin >> boyosh` keyboard er jonno opekkha kore na — buffer er `Salek` ke `int` banate giye **fail kore**। Ar ekbar fail korle `cin` error mode e dhuke jay ar **porer kono `cin` kaj kore na** — tai baki shob variable nijer initial value te thake।
(Ei jonno-i initialize kora joruri — na korle garbage dekhato, obostha bojha jeto na।)

**Q: Type bachar niyom?**
Bastobota mene, sohoj dekhe na। "Ei jinish bastobe kemon? Sobcheye boro ta ki? Doshomik lagey? Text na number?" Classic bhul: phone number `int` e (shurur 0 ude jay, 11 digit ate na), taka `double` e (0.1+0.2 somossa)।

---

## 05 — Operators

**Q: `/` ar `%` er difference?**
`17 / 5 = 3` (bhagphol — koybar jay)। `17 % 5 = 2` (bhagshesh — ki pore thake)। Check: `3 × 5 + 2 = 17`.

**Q: `%` kothay kothay lagey?**
1. Jugmo/bijor — `n % 2 == 0`
2. Sesh digit — `1234 % 10 = 4`
3. Sesh digit felе dewa — `1234 / 10 = 123` (`%` sesh ta **ane**, `/` shuru ta **rakhe**)
4. Cycle — `(ghonta + 5) % 12` (ghori, circular array)
5. Bibhajjota — `n % 3 == 0` (FizzBuzz puropuri ei tar upor)

**Q: `7.5 % 2` kaj kore?**
Na — compile error। `%` shudhu purno shongkha (`int`) er sathe।

**Q: `=` ar `==` er difference? Bhul korle ki hoy?**
`=` assignment (rakho), `==` comparison (prosno)। `if (x = 5)` likhle x e 5 boshiye jay ar sorto shob shomoy true hoy — **error o dey na**, chup-chap bhul kore। Beginner er 1 nombor bhul।

**Q: `&&` ar `||`?**
`&&` (AND) — **duita-i** true hole true ("chaa **ebong** biscuit")। `||` (OR) — **kompokkhe ekta** true hole true ("chaa **othoba** coffee")। `||` e duita-i true hole o uttor true — "thik ekta" mane na। `!` (NOT) ulta kore dey।

**Q: `cout << num % 2 == 0;` — ei ta keno bhul?**
`<<` er precedence `==` er cheye **beshi**, tai compiler porey `(cout << num % 2) == 0` — mane cout er result ke 0 er sathe tulona kore। Bracket dite hobe: `cout << (num % 2 == 0);`
**Niyom: `cout` er vitore tulona korle bracket must.**

**Q: Precedence mukhosto korte hobe?**
Na। Ekta-i niyom: **sondeho hole bracket dao**। `(a >= 18) && (a <= 60)` — bracket free, ar pore porte sohoj। Interview e bracket dile keu kichu bole na; na diye bhul korle bole।

**Q: Short-circuit evaluation ki?** *(bonus)*
`&&` e bam pash false hole daan pash **cholei na** (uttor to false-i)। `||` e bam pash true hole daan pash cholе na। Ei jonno `if (ptr != nullptr && ptr->value > 5)` nirapod — `ptr` null hole ditiyo ongsho chole na, crash hoy na।

---

## 06 — if / else if / else

**Q: `if` kivabe kaj kore?**
Sorto true hole `{ }` er vitorer kaj chole, false hole **puro block skip** hoy। CSS er `@media (max-width: 768px) { ... }` er moto — sorto mille niyom khate।

**Q: `if (x = 5)` likhle ki hoy?**
(1) `x` er vitore 5 **boshiye** dey — purono value noshto, (2) tarpor 5 ke sorto hishebe dekhe, (3) C++ e **0 chhara jekono number true** — tai sorto shob shomoy true, `else` kokhono chole na। Compile error nai।
Bacha-r upay — **Yoda condition**: `if (5 == x)`. Bhule `=` likhle compiler error dibe (5 er vitore kichu rakha jay na)।

**Q: `if (sorto);` — ei `;` ta ki kore?**
"if er kaj kichu nai" — tarpor er `{ }` ta swadhin block hoye **shob shomoy chole**। Chup-chap bug, error nai।

**Q: `{ }` na dile?**
`if` er sathe **shudhu porer ekta line** jore। Ditiyo line indent kora thakleo if er bahire — shob shomoy chole। Apple er 2014 er "goto fail" security bug ei karone।
**Niyom: ek line holeo `{ }` dao।**

**Q: `else` shobdo bhule khali `{ }` likhle?**
Oi block `if` chain er sathe jora thake na — swadhin block, **shob shomoy chole**। Tai duita branch-i print kore (`PassFail`)। Compiler error dey na।

**Q: `else if` chain er order keno guruttopurno?**
Upor theke niche porikkha, **prothom match** chole, baki shob skip। Tai **kothin sorto age, sohoj sorto pore**।
```cpp
if (m >= 60) { B }        // ❌ 95 o ekhane ateke jabe
else if (m >= 80) { A+ }  // kokhono pouchabe na
```
Order: 80 → 70 → 60 → 50 → else (boro theke chhoto)।

**Q: FizzBuzz e classic bhul?**
```cpp
if (n%3==0) Fizz; else if (n%5==0) Buzz; else if (n%15==0) FizzBuzz;  // ❌
```
15 prothom sorto tei (15%3==0) ateke "Fizz" bole। `n%15==0` age likhte hobe — sobcheye kothin sorto shuru te।

**Q: Kivabe test korbe?**
**Boundary testing** — seema er thik upore-niche: 79/80/81, 39/40। Programming er sobcheye common bug **off-by-one** (`>` vs `>=`) sekhanei lukay।

**Q: `switch` kobe, `if/else` kobe?**
`switch` — **thik thik value** melanor jonno (menu 1/2/3, `case 'A':`)। Range hoy na (`case > 80` bhul)। `if/else if` — range er jonno (`>= 80`)।

**Q: `switch` e `break` na dile?**
**Fall-through** — porer `case` gulo o cholte thake jotokkhon na `break` ba block sesh। Kokhono ichha kore kora hoy, kintu prai shomoy bug। `default` = `else`.

---

## 07 — Loops

**Q: `while` ar `if` er sompork?**
`while` holo "bar bar `if`" — sorto true holе kaj kore, tarpor **abar porikkha kore**, jotokkhon true।

**Q: Loop er tinta ongsho?**
(1) shuru, (2) kotokkhon cholbe, (3) protibar ki hobe।
`while` e tinta tin jaygay chhoraano। `for` ek jaygay ane: `for (int i = 1; i <= 5; i++)` — duita `;` diye alada (comma na)।

**Q: `for` kobe, `while` kobe?**
Koybar cholbe **jani** → `for`. Koybar cholbe **jani na** (user quit na bola porjonto) → `while`. LeetCode e 90% `for`.

**Q: Infinite loop keno hoy?**
Tritiyo ongsho sorto ke false er dike **thele na**। `for (int i = 1; i <= 5; i--)` — `i` komche kintu sorto `i <= 5`, tai aro beshi true hoy, kokhono thame na। Thamate `Ctrl+C`.
`i--` chaile sorto o ulte dite hobe: `for (int i = 5; i >= 1; i--)`.

**Q: Accumulator pattern ki?**
Loop er **bahire** patro, **vitore** joma, **bahire** dekhano:
```cpp
int sum = 0;                        // bahire — vitore dile protibar 0 hoye jabe
for (int i = 1; i <= 10; i++) sum += i;
cout << sum;                        // bahire — vitore dile 10 bar chapbe
```

**Q: C++ e ki true, ki false?**
`0` = false. **`0` chhara jekono number = true** (1, -5, 100 shob true)।

**Q: `if (i % 3)` keno bhul?**
`%` ekta **number** dey (0, 1, 2), bool na। `i % 3` er uttor `0` hole-i bhag jay — kintu `0` mane **false**! Tai `if (i % 3)` er mane dnaray **"3 diye bhag jay NA"** — ekdom ulta।
Thik: `if (i % 3 == 0)`.
**Niyom: `%` er result ke `== 0` diye tulona kore bool banate hobe।**

**Q: FizzBuzz — puro uttor**
```
loop 1..n
  i % 15 == 0  → FizzBuzz     ← SOBCHEYE KOTHIN SORTO AGE
  i % 3  == 0  → Fizz
  i % 5  == 0  → Buzz
  else         → i
```
3 er sorto age dile 15 sekhanei ateke jabe, FizzBuzz kokhono chapbe na। `i % 15 == 0` ar `i % 3 == 0 && i % 5 == 0` ek-i jinish।

---

## 08 — Functions

**Q: Function ki, keno?**
Ekbar likhe bar bar daka jay emon ekta kaj। Elementor er Global Widget/Template er moto — ekbar banao, jekhane khushi boshao, ekbar bodlale shob jaygay bodlay। `getline`, `cout` — ei gula o function, onno keu likhe rekhe diyeche।

**Q: Function er gothon?**
```
returnType  naam ( parameter )  {  body  }
    int      jog  (int a, int b) { return a + b; }
```
- **return type** — ki ferot dibe (`int`, `bool`, `string`, ba `void`)
- **parameter** — ki ki lagbe (variable er moto, **type shoho**)
- **body** — ki kaj korbe

**Q: `void` mane ki? Duibar likhle somossa?**
`void` = "kichu ferot dibo na"। Eta naam na, **return type** — protita function er nijer ekta lagey। Joto function `void` hote pare, thik jemon joto variable `int` hote pare (`int a; int b;`)। Na likhle: `error: C++ requires a type specifier`.

**Q: Parameter e type na dile?**
`void bolo(kotha)` → `error: unknown type name 'kotha'`. Parameter ekta variable declaration-i, **type lagbei**: `void bolo(string kotha)`.

**Q: Function likhle-i ki chole?**
**Na।** Likhe rakha = machine banano। **Daka** (`bolo("hi");`) = button chapa। Na dakle kokhono chole na।

**Q: Kothay likhte hobe?**
`main` er **upore** (na hole "undeclared identifier")। Ar `main` **ekta-i** — duita likhle `error: redefinition of 'main'`. Function gula upore, ekta `main` sheshe।

**Q: `cout << jog(5, 3)` kivabe kaj kore?**
`jog(5, 3)` age chole → `8` niye fire ashe → line ta hoye jay `cout << 8`. **Function call ekta value hoye jay** — tai `cout` e dewa jay, variable e rakha jay, onno hishab e use kora jay: `jog(5,3) * 2`, `jog(jog(1,2), 4)`.

**Q: `void` ar value-returning function er difference?**
`void` nije kaj kore (print kore), kichu dey na — `int x = bolo("hi");` error। Value-returning function fol dey, print kore na — caller ja khushi kore।
**Bhalo design: function hoy hishab koruk, noyto dekhak — duita ek shathe na.** Hishab kore ferot dile seta jekhane khushi use kora jay।

**Q: `bool` function keno bhalo?**
```cpp
bool isEven(int n) { return n % 2 == 0; }
if (isEven(num)) { ... }        // "if is-even num" — English er moto
```
`if (num % 2 == 0)` er cheye sposto। Naming: `bool` function `is`/`has`/`can` diye shuru — `isEven`, `isEmpty`, `hasNext`.

**Q: Ei ta keno kharap?**
```cpp
bool isEven(int n) { if (n % 2 == 0) return true; else return false; }
```
`n % 2 == 0` nije-i true/false — take abar `if` e dhokano ojotha। `return n % 2 == 0;` jothesto।

**Q: `isOdd` kivabe likhbe?**
```cpp
bool isOdd(int n) { return !isEven(n); }
```
`%` abar na likhe `isEven` ke dake ar `!` diye ulta kore। **Function er vitore function daka jay।** Laabh: "jugmo" er songa bodlale `isOdd` nijer theke thik thake — ek jaygay sotto।

**Q: Code duplication keno kharap?**
Ek-i kaj duita function e likhle (`bolo` ar `boloNew`) — kokhono ektar logic bodlale onnota purono theke jay, duita alada achoron kore, bug khuje pawa jay na। **Ekta kaj = ekta function.**

**Q: Scope ki?** *(07 theke)*
Variable jei `{ }` er vitore declare kora, seta-i tar elaka। Block sesh hole se noshto hoy, bahir theke use kora jay na। Loop/function er vitorer variable protibar notun kore toiri hoy।

---

## 09 — Pointers & References

**Q: Memory kivabe kaj kore?**
RAM ekta bishal line, protita ghor er ekta number (thikana) ache। `int age = 25;` mane — 4 byte jayga newa holo, tate 25 rakha holo, ar oi ghor er naam dewa holo `age`. Naam manusher jonno, thikana computer er asol jinish।

**Q: `&` ki kore?**
"er thikana" (address-of)। `&age` → `0x16f0de9bc`. Protibar run e thikana bodlay — OS protibar alada ghor dey।

**Q: `int` 4 byte — kivabe proman korba?**
Duita porporeer `int` er thikana chapao — thik **4** er pharak hobe। Ba `sizeof(int)` → 4, `sizeof(double)` → 8, `sizeof(char)` → 1।

**Q: Pointer ki?**
Ekta variable ja **onno variable er thikana** rakhe। `int* p = &age;` — `p` er vitore 25 nai, ache "25 kothay ache" tar thikana।
HTML er `<a href="#contact">` er moto — link ta section na, section er **pothonirdesh**।

**Q: `p` ar `*p` er difference? (MUKHOSTO)**
```cpp
int x = 25;  int* p = &x;
```
| Lekha | Ki | Value |
|---|---|---|
| `x` | asol jinish | 25 |
| `&x` | x er thikana | 0x16f0... |
| `p` | thikana rakhe | 0x16f0... |
| `*p` | thikana theke jinish | 25 |

**`p` = thikana. `*p` = value.** (`p` = **p**ointer = **p**oth dekhay = thikana)
`&` ar `*` eke oporer ulta: `x ──&──▶ thikana ──*──▶ x`

**Q: `int* p` ar `*p` — `*` er mane ek?**
Na, duita alada:
- **Type er sathe** (`int* p`) → "pointer **banacchi**" (ghoshona)
- **Naam er sathe** (`*p`) → "vitorer jinish **chai**" (dereference)

**Q: Pass by value ki? Keno somossa?**
C++ er default — function e **value er copy** jay। Tai function e bodlale asol variable e lage na:
```cpp
void f(int x) { x = 999; }   int num = 5;  f(num);  // num ekhono 5
```
Copy ekta alada ghor, function sesh hole mare jay।

**Q: Pointer diye kivabe asol ta bodlabo?**
```cpp
void f(int* x) { *x = 999; }    f(&num);    // num ekhon 999
```
Thikana pathao (`&num`), function `*` diye oi ghore boshiye dey।
*Chithir moto: value = **photocopy** pathano, pointer = **thikana** pathano.*

**Q: Reference ki?**
Ekta bidyoman variable er **notun daknaam (alias)** — notun ghor na, ek-i ghor duita naam:
```cpp
int age = 25;  int& boyosh = age;
boyosh = 30;   cout << age;      // 30
```
```cpp
void f(int& x) { x = 999; }     f(num);     // & ba * lage na
```

**Q: Pointer ar reference er difference? (INTERVIEW)**
| | Pointer | Reference |
|---|---|---|
| Ghoshona | `int* p` | `int& r` |
| Dakar somoy | `f(&num)` | `f(num)` |
| Vitore use | `*p` | `r` shojasuji |
| Null hote pare? | ✅ `nullptr` | ❌ na |
| Re-assign? | ✅ | ❌ ekbar bandha mane ajibon |

*"Pointer ekta variable ja thikana rakhe — null hote pare, re-assign kora jay. Reference ekta bidyoman variable er alias — obosshoi initialize korte hobe, null hoy na, re-assign hoy na. Default e reference use kora bhalo (poriskar, nirapod); pointer lagey jokhon optional-ness (nullptr) ba re-assignment dorkar — jemon linked list, tree।"*

**Q: `void f(int x)` ar `void f(int& x)` er body ek, tobu fol alada keno?**
Body duitai `x = 999;` — pharak shudhu **parameter e ekta `&`**। Oi ekta chinho thik kore dey copy jabe na asol er alias jabe।

---

## 10 — Classes & OOP

**Q: Class keno lagey?**
Somporkito data alada variable e rakhle 3 jon chhatro = 12 ta variable, 100 jon = 400 ta। Class ekta **notun type** banay — `Student s1;` ekta variable, vitore shob ekshathe bandha। Elementor er custom widget er moto.

**Q: `struct` ar `class` er difference?**
Technically **ekta-i**: default access। `struct` → public, `class` → private। Baki shob (constructor, member function, inheritance) ek। Convention e `struct` shudhu data rakhar jonno, `class` jokhon behavior + encapsulation lagey।

**Q: Class er sheshe `;` keno?**
`};` — class/struct er por semicolon **lagey** (function er por lage na)। Bhulle bibhranto error ashe।

**Q: Class vs Object?**
Class = **nokša** (blueprint)। Object = oi nokša theke banano asol jinish। `Student` nokša, `s1`/`s2`/`s3` object। Nokša ekta, object joto khushi।

**Q: Member function er vitore `nam` likhle kar `nam`?**
Je object theke daka hoyeche, tar। `s1.dekhao()` e `nam` mane `s1.nam`, `s2.dekhao()` e `s2.nam`. Ek-i function, protibar alada malik।
**OOP er mul kotha: data ar tar upor er kaj — ek jaygay bandha।**

**Q: Constructor ki?**
Bishesh member function — **naam class er naam**, **kono return type nai** (`void` o na), ar **object toirir shomoy nijer theke chole**।
```cpp
Student(string n, int b, double c) { nam = n; ... }
Student s1("Arman", 25, 3.5);        // ek line e toiri + bhorti
```
Boro laabh: constructor thakle `Student s4;` **compile error** — half-initialized object toiri-i hote pare na।

**Q: Destructor (`~Student()`) ki? Kobe lagey?**
Constructor er ulta — object **morar** shomoy chole। Lagey jokhon object kono resource dhore rakhe: heap memory (`new`), file handle, connection। Destructor e seta chhere dite hoy। Ei pattern = **RAII** (Resource Acquisition Is Initialization)।

**Q: `Student::Student(...)` — `::` ki?**
Scope resolution operator — "Student class er vitorer"। Class er **bahire** function er shorir likhle lagey। Chhoto class e vitorei lekha jay; boro project e ghoshona `.h` e, shorir `.cpp` e।

**Q: Encapsulation ki? Keno?**
Data `private` kore lukano, ar bahirer jonno `public` function (darja) dewa — jate protita poriborton **porikkha kore** hoy।
```cpp
s1.cgpa = 99.5;        // ❌ private — compile error
s1.setCgpa(99.5);      // ✅ chole, kintu validation e atke 0 hoy
```
Tinta laabh: (1) invalid state thekano jay, (2) vitorer implementation bodlano jay bahir na venge, (3) data kothay bodlacche — ek jaygay, debug sohoj।
*Bank er analogy: vault e (private data) shorashori jaowa jay na, counter (public function) diye jete hoy।*

**Q: Constructor eo setter diye jaowa keno?**
```cpp
Student(...) { setCgpa(c); }     // shorashori cgpa = c; na
```
Validation **ek jaygay** thake। Jekhan theke-i value boshuk, ek-i porikkha chole।

**Q: `get` ar `set` er pharak?**
| | Parameter | Return |
|---|---|---|
| `void setX(double c)` | **ney** | dey na |
| `double getX()` | ney na | **dey** |
set = boshao (bahir→vitor), get = nao (vitor→bahir)।

**Q: Function overloading ki? Shudhu return type alada hole?**
Ek-i naam e ekadhik function, jader **parameter list alada** (shongkha ba type)। Compiler argument dekhe thik ta beche ney (**overload resolution**)।
**Shudhu return type alada hole overload hoy na** — `f();` likhle call site theke bojha jay na kon ta lagbe।
Overload tokhon-i bhalo jokhon kaj ta sotti ek dhoroner: `print(int)`, `print(string)`. Alada kaj e ek naam (get/set) dewa bhul।

---

## 11 — Memory (Stack vs Heap)

**Q: Stack ar Heap er difference?**
| | Stack | Heap |
|---|---|---|
| Jayga dey | compiler nije | tumi (`new`) |
| Poriskar kore | **nije** (`}` e) | **tumi** (`delete`) |
| Gothi | druto | dhire |
| Akar | chhoto (~1-8 MB) | bishal |
| Ayu | block sesh porjonto | `delete` na kora porjonto |

```cpp
Test t;                    // stack — } e nije mare
Test* t = new Test();      // heap  — na marle mare na
```

**Q: Heap keno lagey, stack to sohoj?**
1. **Akar age jana na thakle** — `int* arr = new int[n];` (n runtime e jana)
2. **Function sesh hoyeo jinish ta lagbe** — stack er jinish `return` er por more jay; tar thikana return korle **dangling pointer** (mora jinish er thikana, undefined behavior)
3. **Linked list, tree, graph** — node cholte cholte toiri hoy, agye shongkha jana thake na

**Q: Memory leak ki? Ki kore hoy?**
`new` korle kintu `delete` na korle — ar pointer ta scope theke beriye gele oi memory er thikana-i hariye jay, ar kokhono ferot dewa jabe na।
```cpp
{ Test* t = new Test(); }     // ← leak, destructor cholеni
```
Chhoto program e kichu hoy na (OS ferot ney), kintu **long-running server** e protita request e ektu ektu jome — ekdin out-of-memory crash।
**Niyom: protita `new` er ekta `delete`.**

**Q: `delete` mone rakha-i to jothesto, somossa ki?**
Manush bhule jay। `return`, `throw`, ba ekta bhul path — `delete` er line porjonto pouchay na:
```cpp
Test* t = new Test();
if (bhul) return;        // ← leak
delete t;
```

**Q: Smart pointer ki? Kivabe kaj kore?**
`#include <memory>`
```cpp
{ unique_ptr<Test> t = make_unique<Test>(); }    // delete likhte hoy NA
```
`unique_ptr` nije ekta **stack object** — `}` e nije mare, ar tar **destructor** heap er jinish ta `delete` kore dey।
**Stack er automatic byabostha diye heap samlano = RAII.**

**Q: Tinta smart pointer?**
| | Kaj | Kobe |
|---|---|---|
| `unique_ptr` | ekjon-i malik, copy hoy na (move hoy) | default, 90% khetre |
| `shared_ptr` | koyekjon malik, reference count 0 hole delete | sotti share korte hole |
| `weak_ptr` | dekhe kintu malik na | `shared_ptr` er circular reference thekate |

**Q: Modern C++ e raw pointer / `new` use koro? (INTERVIEW)**
*"Malikana bojhate raw pointer use kori na — `unique_ptr`/`shared_ptr` use kori, jate RAII automatic cleanup dey ar leak/double-delete na hoy। Raw pointer shudhu tokhon jokhon malikana nai — shudhu kono jinish ke 'dekhachhi', tar ayu onno keu samlacche। `new`/`delete` adhunik code e prai kokhono likhi na, `make_unique`/`make_shared` diye kaj hoy।"*

**Q: RAII ki?**
Resource Acquisition Is Initialization — object jonmanor shomoy resource ney, morar shomoy (destructor e) chhere dey। Memory, file handle, lock, connection — shob ei pattern e samlano hoy। C++ er sobcheye guruttopurno idiom।

---

## Fundamentals SESH ✅ (01–11)

Erpor: 02-stl → 03-algorithms → 04-data-structures
