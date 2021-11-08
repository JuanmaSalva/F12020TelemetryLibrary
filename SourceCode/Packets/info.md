##Packed IDs

---

Packet Name = Value = Description\
Motion = 0 = Contains all motion data for player’s car – only sent while player is in control\
Session = 1 = Data about the session – track, time left\
Lap Data = 2 = Data about all the lap times of cars in the session\
Event = 3 = Various notable events that happen during a session\
Participants = 4 = List of participants in the session, mostly relevant for multiplayer\
Car Setups = 5 = Packet detailing car setups for cars in the race\
Car Telemetry = 6 = Telemetry data for all cars\
Car Status = 7 = Status data for all cars such as damage\
Final Classification = 8 = Final classification confirmation at the end of a race\
Lobby Info = 9 = Information about players in a multiplayer lobby

---
---

##Tyre indicies
0 = Rear left
1 = Rear right
2 = Front left
3 = Front right

---
---

##Event data

---
####String codes
SSTA = Session started\
SEND = Session ended\
FTLP = Fasted lap\
RTMT = Retirement\
DRSE = DRS enabled\
DRSD = DRS desabled\
TMPT = Team mate in pits\
CHQF = Chequered flag\
RCWN = Race winner\
PENA = Panalty issued\
SPTP = Speed trap triggered

---
####Penalty types
0 = Drive through\
1 = Stop Go\
2 = Grid penalty\
3 = Penalty reminder\
4 = Time penalty\
5 = Warning\
6 = Disqualified\
7 = Removed from formation lap\
8 = Parked too long timer\
9 = Tyre regulations\
10 = This lap invalidated\
11 = This and next lap invalidated\
12 = This lap invalidated without reason\
13 = This and next lap invalidated without reason\
14 = This and previous lap invalidated\
15 = This and previous lap invalidated without reason\
16 = Retired\
17 = Black flag timer

---
####Infringement types
0 Blocking by slow driving\
1 = Blocking by wrong way driving\
2 = Reversing off the start line\
3 = Big Collision\
4 = Small Collision\
5 = Collision failed to hand back position single\
6 = Collision failed to hand back position multiple\
7 = Corner cutting gained time\
8 = Corner cutting overtake single\
9 = Corner cutting overtake multiple\
10 = Crossed pit exit lane\
11 = Ignoring blue flags\
12 = Ignoring yellow flags\
13 = Ignoring drive through\
14 = Too many drive throughs\
15 = Drive through reminder serve within n laps\
16 = Drive through reminder serve this lap\
17 = Pit lane speeding\
18 = Parked for too long\
19 = Ignoring tyre regulations\
20 = Too many penalties\
21 = Multiple warnings\
22 = Approaching disqualification\
23 = Tyre regulations select single\
24 = Tyre regulations select multiple\
25 = Lap invalidated corner cutting\
26 = Lap invalidated running wide\
27 = Corner cutting ran wide gained time minor\
28 = Corner cutting ran wide gained time significant\
29 = Corner cutting ran wide gained time extreme\
30 = Lap invalidated wall riding\
31 = Lap invalidated flashback used\
32 = Lap invalidated reset to track\
33 = Blocking the pitlane\
34 = Jump start\
35 = Safety car to car collision\
36 = Safety car illegal overtake\
37 = Safety car exceeding allowed pace\
38 = Virtual safety car exceeding allowed pace\
39 = Formation lap below allowed speed\
40 = Retired mechanical failure\
41 = Retired terminally damaged\
42 = Safety car falling too far back\
43 = Black flag timer\
44 = Unserved stop go penalty\
45 = Unserved drive through penalty\
46 = Engine component change\
47 = Gearbox change\
48 = League grid penalty\
49 = Retry penalty\
50 = Illegal time gain\
51 = Mandatory pitstop

---
---
##Track Ids
0 = Melburne\
1 = Paul Ricard\
2 = Shangai\
3 = Sakhir (Bahrain)\
4 = Spain\
5 = Monaco\
6 = Montreal\
7 = Silverstone\
8 = Hockenheim\
9 = Hungaroring\
10 = Spa\
11 = Monza\
12 = Singapore\
13 = Suzuka\
14 = Abu Dhabi\
15 = Texas\
16 = Brazil\
17 = Austria\
18 = Sochi\
19 = Mexico\
20 = Baku\
21 = Sakhir short\
22 = Silverstone short\
23 = Texas short\
24 = Suzuka short\
25 = Hanoi\
26 = Zandvoort

---
---
##Team IDs
0 = Mercedes\
1 = Ferrari\
2 = Red Bull Racing\
3 = Williams\
4 = Racing Point\
5 = Renault\
6 = Alpha Tauri\
7 = Haas\
8 = McLaren\
9 = AlphaRomeo\
10 = McLaren 1988\
11 = McLaren 1991\
12 = Williams 1992\
13 = Ferrari 1995\
14 = Williams 1996\
15 = McLaren 1998\
16 = Ferrari 2002\
17 = Ferrari 2004\
18 = Renauls 2006\
19 = Ferrari 2007\
20 = McLaren 2008\
21 = Red Bull 2010\
22 = Ferrari 1976\
23 = ART GRand Prix\
24 = Campos Vexatec Racing\
25 = Carlin\
26 = Charouz RacinG System\
27 = DAMS\
28 = Russian Time\
29 = MP Motorsport\
30 = Pertamina\
31 = McLAren 1990\
32 = Trident\
33 = BWT Arden\
34 = McLaren 1976\
35 = Lotus 1972\
36 = Ferrari 1979\
37 = McLaren 1982\
38 = Williams 2003\
39 = Brawn 2009\
40 = Lotus 1978\
41 = F1 Generic car\
42 = Art GP '19\
43 = Campos '19\
44 = Carlin '19\
45 = Sauber Junior Charouz ’19\
46 = Dams '19\
47 = Uni-Virtuosi '19\
48 = MP Motorsport '19\
49 = Prema '19\
50 = Trident '19\
51 = Arden '19\
53 = Benetton 1994\
54 = Benetton 1995\
55 = Ferrari 2000\
56 = Jordan 1991 \
255 = My Team

---
---
##Drivers IDs

0 Carlos Sainz\
1  =Daniil Kvyat\
2  =Daniel Ricciardo\
6  =Kimi Räikkönen\
7  =Lewis Hamilton\
9  =Max Verstappen\
10 = Nico Hulkenburg\
11 = Kevin Magnussen\
12 = Romain Grosjean\
13 = Sebastian Vettel\
14 = Sergio Perez\
15 = Valtteri Bottas\
17 = Esteban Ocon\
19 = Lance Stroll\
20 = Arron Barnes\
21 = Martin Giles\
22 = Alex Murray\
23 =  Lucas Roth\
24 = Igor Correia\
25 = Sophie Levasseur\
26 = Jonas Schiffer\
27 = Alain Forest\
28 = Jay Letourneau\
29 = Esto Saari\
30 =  Yasar Atiyeh\
31 = Callisto Calabresi\
32 = Naota Izum\
33 = Howard Clarke\
34 = Wilheim Kaufmann\
35 = Marie Laursen\
36 = Flavio Nieves\
37 = Peter Belousov\
38 = Klimek Michalski\
39 = Santiago Moreno\
40 = Benjamin Coppens\
41 = Noah Visser\
42 = Gert Waldmuller\
43 = Julian Quesada\
44 = Daniel Jones\
45 = Artem Markelov\
46 = Tadasuke Makino\
47 = Sean Gelael\
48 = Nyck De Vries\
49 = Jack Aitken\
50 = George Russell\
51 = Maximilian Günther\
52 = Nirei Fukuzumi\
53 = Luca Ghiotto\
54 = Lando Norris\
55 = Sérgio Sette Câmara\
56 = Louis Delétraz\
57 = Antonio Fuoco\
58 = Charles Leclerc\
59 = Pierre Gasly\
62 = Alexander Albon\
63 = Nicholas Latifi\
64 = Dorian Boccolacci\
65 = Niko Kari\
66 = Roberto Merhi\
67 = Arjun Maini\
68 = Alessio Lorandi\
69 = Ruben Meijer\
70 = Rashid Nair\
71 = Jack Tremblay\
74 = Antonio Giovinazzi\
75 = Robert Kubica\
78 = Nobuharu Matsushita\
79 = Nikita Mazepin\
80 = Guanya Zhou\
81 = Mick Schumacher\
82 = Callum Ilott\
83 = Juan Manuel Correa\
84 = Jordan King\
85 = Mahaveer Raghunathan\
86 = Tatiana Calderon\
87 = Anthoine Hubert\
88 = Guiliano Alesi\
89 = Ralph Boschung

---
---

## Nationality IDs

1 = American\
2 = Argentinean\
3 = Australian\
4 = Austrian\
5 = Azerbaijani\
6 = Bahraini\
7 = Belgian\
8 = Bolivian\
9 = Brazilian\
10 = British\
11 = Bulgarian\
12 = Cameroonian\
13 = Canadian\
14 = Chilean\
15 = Chinese\
16 = Colombian\
17 = Costa Rican\
18 = Croatian\
19 = Cypriot\
20 = Czech\
21 = Danish\
22 = Dutch\
23 = Ecuadorian\
24 = English\
25 = Emirian\
26 = Estonian\
27 = Finnish\
28 = French\
29 = German\
30 = Ghanaian\
31 = Greek\
32 = Guatemalan\
33 = Honduran\
34 = Hong Konger\
35 = Hungarian\
36 = Icelander\
37 = Indian\
38 = Indonesian\
39 = Irish\
40 = Israeli\
41 = Italian\
42 = Jamaican\
43 = Japanese\
44 = Jordanian\
45 = Kuwaiti\
46 = Latvian\
47 = Lebanese\
48 = Lithuanian\
49 = Luxembourger\
50 = Malaysian\
51 = Maltese\
52 = Mexican\
53 = Monegasque\
54 = New Zealander\
55 = Nicaraguan\
56 = North Korean\
57 = Northern Irish\
58 = Norwegian\
59 = Omani\
60 = Pakistani
61 = Panamanian\
62 = Paraguayan\
63 = Peruvian\
64 = Polish\
65 = Portuguese\
66 = Qatari\
67 = Romanian\
68 = Russian\
69 = Salvadoran\
70 = Saudi\
71 = Scottish\
72 = Serbian\
73 = Singaporean\
74 = Slovakian\
75 = Slovenian\
76 = South Korean\
77 = South African\
78 = Spanish\
79 = Swedish\
80 = Swiss\
81 = Thai\
82 = Turkish\
83 = Uruguayan\
84 = Ukrainian\
85 = Venezuelan\
86 = Welsh\
87 = Barbadian\
88 = Vietnamese

---
---

## Surface types

0 = Tarmac\
1 = Rumble strip\
2 = Concrete\
3 = Rock\
4 = Gravel\
5 = Mud\
6 = Sand\
7 = Grass\
8 = Water\
9 = Cobblestone\
10 = Metal\
11 = Ridged

---
---

##Button flags

0x0001 = Cross or A\
0x0002 = Triangle or Y\
0x0004 = Circle or B\
0x0008 = Square or X\
0x0010 = D-pad Left\
0x0020 = D-pad Right\
0x0040 = D-pad Up\
0x0080 = D-pad Down\
0x0100 = Options or Menu\
0x0200 = L1 or LB\
0x0400 = R1 or RB\
0x0800 = L2 or LT\
0x1000 = R2 or RT\
0x2000 = Left Stick Click\
0x4000 = Right Stick Click

---
---

##Penalty types

0 = Drive through\
1 = Stop Go\
2 = Grid penalty\
3 = Penalty reminder\
4 = Time penalty\
5 = Warning\
6 = Disqualified\
7 = Removed from formation lap\
8 = Parked too long timer\
9 = Tyre regulations\
10 = This lap invalidated\
11 = This and next lap invalidated\
12 = This lap invalidated without reason\
13 = This and next lap invalidated without reason\
14 = This and previous lap invalidated\
15 = This and previous lap invalidated without reason\
16 = Retired\
17 = Black flag timer

---
---

##Infrigement type

0 = Blocking by slow driving\
1 = Blocking by wrong way driving\
2 = Reversing off the start line\
3 = Big Collision\
4 = Small Collision\
5 = Collision failed to hand back position single\
6 = Collision failed to hand back position multiple\
7 = Corner cutting gained time\
8 = Corner cutting overtake single\
9 = Corner cutting overtake multiple\
10 = Crossed pit exit lane\
11 = Ignoring blue flags\
12 = Ignoring yellow flags\
13 = Ignoring drive through\
14 = Too many drive throughs\
15 = Drive through reminder serve within n laps\
16 = Drive through reminder serve this lap\
17 = Pit lane speeding\
18 = Parked for too long\
19 = Ignoring tyre regulations\
20 = Too many penalties\
21 = Multiple warnings\
22 = Approaching disqualification\
23 = Tyre regulations select single\
24 = Tyre regulations select multiple\
25 = Lap invalidated corner cutting\
26 = Lap invalidated running wide\
27 = Corner cutting ran wide gained time minor\
28 = Corner cutting ran wide gained time significant\
29 = Corner cutting ran wide gained time extreme\
30 = Lap invalidated wall riding\
31 = Lap invalidated flashback used\
32 = Lap invalidated reset to track\
33 = Blocking the pitlane\
34 = Jump start\
35 = Safety car to car collision\
36 = Safety car illegal overtake\
37 = Safety car exceeding allowed pace\
38 = Virtual safety car exceeding allowed pace\
39 = Formation lap below allowed speed\
40 = Retired mechanical failure\
41 = Retired terminally damaged\
42 = Safety car falling too far back\
43 = Black flag timer\
44 = Unserved stop go penalty\
45 = Unserved drive through penalty\
46 = Engine component change\
47 = Gearbox change\
48 = League grid penalty\
49 = Retry penalty\
50 = Illegal time gain\
51 = Mandatory pitstop