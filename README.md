# map-coloring
School exercise: coloring a map with N countries

Noțiuni generale

În implementarea aplicației am ținut cont:
- să am nume de variabile care să facă codul ușor de urmărit
- să fac cât mai simplu de introdus datele de către utilizator (citindu-le într-un format "human readable"). De exemplu, deși lucrez cu o matrice de adiacență în care fac legătura dintre țările învecinate, utilizatorul nu introduce cifre (indecși), ci nume de țări.

Deci aplicația este atât pe înțelesul programatorului (vezi și comentariile din cod), cât și pe înțelesul utilizatorului (mesaje ușor de urmărit).

Definirea variabilelor

Avem număr de țări, număr de culori, listă de țări, listă de culori, map - matrice de adiacență, countries_colors - aici salvăm culorile pentru fiecare țară, adică rezultatul problemei.

Algoritmul

Se citesc datele de intrare (practic o hartă, care este o listă de țări și vecinii pentru fiecare țară + culorile posibile).

În momentul citirii vecinilor fiecărei țări, țările sunt căutate în lista de țări și matricea de adiacență este actualizată în așa fel încât să avem 1 numai acolo unde țările sunt învecinate.

Luăm pe rând țările din listă și încercăm pe rând culori din lista de culori. Ne asigurăm că două țări vecine nu au aceeași culoare. Ne folosim de matricea de adiacență pentru a găsi vecinii și de countries_colors pentru a găsi culorile folosite deja.

La final afișăm culoarea selectată pentru fiecare țară.

Concluzii

Faptul că am codificat datele de intrare ca o simplă matrice de adiacență ajută să detectăm ușor vecinii țărilor atunci când căutăm culori pentru ele. De asemenea, faptul că folosim de regulă indecși ai țărilor și ai culorilor - ajută la optimizare (memorie și viteză de calcul). Totuși, atât la citire, cât și la afișare am preferat să citim și să afișăm nume de culori și nume de țări. Rezultatul e o aplicație utilă pentru un programator care vrea să învețe să programeze în C.

În munca făcută, am împărțit problema în subprobleme și le-am rezolvat pe rând, căutând soluții și pe internet. Exemplu: citirea în C a unei liste de cuvinte.

Aceasta este o primă variantă de soluție, care poate fi îmbunătățită ulterior. De exemplu, s-ar putea adăuga și elemente grafice (culori sau poate chiar o hartă desenată).
