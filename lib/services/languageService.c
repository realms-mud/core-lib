//*****************************************************************************
// Class: RaceService
// File Name: racialService.c
//
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

mapping languages = ([
    "garblish": ({ "ubonga", "whasit", "brugle", "grah", "magumbi",
        "blarg", "ach", "nurga", "bungo", "nirba", "won-war", "brongo",
        "girble", "wonk", "norga", "nashk", "ishk", "brokus", "wald",
        "vorma", "vingle", "larma", "lurgid", "grungle", "kirg", "bogbog",
        "jurp", "jum", "jalak", "hurg", "hadle", "fent", "famble", 
        "dorg", "darf", "salga", "sumg", "argle", "zand", "carnag", "cag",
        "zug", "zog", "vap", "vurgle", "bup", "nuble", "noog", "muk",
        "walak", "ergunga", "erlak", "razid", "ruba", "rongo", "tirg",
        "tunlgo", "dhurg", "dup", "yonga", "yursa", "yonk", "ulbo", "ong",
        "pernlag", "peldank", "parnaf", "farglo", "forgla", "humanai",
        "nukuleve", "nanga", "blorg", "barda", "bishanko", "burdara",
        "noogalope", "camanargo", "warningo", "qui'nalacar", "nonko",
        "ninzug", "lorkonicoid", "spandalacan"
    }),
    "elven":({ "elen", "lemus", "omenalama", "aedwe", "nurban", "ai'",
        "lanesa", "menaella", "calen", "lienmara", "kirluin", "quaela",
        "karya", "bragola", "parn", "dullach", "khelen", "gurna", "gorgal",
        "spaena", "cam", "dura", "naur", "asca", "ami", "quella", "surna",
        "daew", "zula", "endrelinnadh", "zhucaradh", "burnae", "loomen",
        "sulana", "alabrindo", "nagurdal", "freni", "welana", "uvan",
        "brindi", "ooman", "duleb", "syndwengil", "myandis", "anrobe",
        "faendis", "xendia", "borae", "noduli", "mendidh", " landra",
        "kaendra", "heliga", "haelar", "gondwai", "forois", "pinda",
        "penegrae", "olomra", "iscara", "ulumir", "yendwich", "yaeri",
        "taebdhil", "taernas", "tilidal", "tengwi", "tarnwi", "romodash",
        "raenda", "rini", "ranea", "raladan", "rogloi", "rala", "romwa",
        "eleg", "eali", "erenda", "elgara", "elwi", "eloqu", "emda",
        "enloi", "eros", "elraina", "enelbro", "wa", "wi", "wu", "wei",
        "wenegrul", "wedhas", "wendra", "wursa", "ala", "alsidh", "a",
        "yn", "yurda", "yis", "yengwa", "yndir", "alas", "arga", "anduili",
        "sirn", "senrach", "sinildin", "senai", "sengurs", "simildin",
        "sirnash", "salagandorin", "sinelmiridh", "sanadroika", "zara",
        "zini", "xa", "xaran", "xiesa", "carac'ha", "ingol'adi", "va",
        "vinisti", "bara", "baela", "binildu" }),
    "sylvan": ({ "elen", "lemus", "omenalama", "aedwe", "nurban", "ai'",
        "lanesa", "menaella", "calen", "lienmara", "kirluin", "quaela",
        "karya", "bragola", "parn", "dullach", "khelen", "gurna", "gorgal",
        "spaena", "cam", "dura", "naur", "asca", "ami", "quella", "surna",
        "daew", "zula", "endrelinnadh", "zhucaradh", "burnae", "loomen",
        "sulana", "alabrindo", "nagurdal", "freni", "welana", "uvan",
        "brindi", "ooman", "duleb", "syndwengil", "myandis", "anrobe",
        "faendis", "xendia", "borae", "noduli", "mendidh", " landra",
        "kaendra", "heliga", "haelar", "gondwai", "forois", "pinda",
        "penegrae", "olomra", "iscara", "ulumir", "yendwich", "yaeri",
        "taebdhil", "taernas", "tilidal", "tengwi", "tarnwi", "romodash",
        "raenda", "rini", "ranea", "raladan", "rogloi", "rala", "romwa",
        "eleg", "eali", "erenda", "elgara", "elwi", "eloqu", "emda",
        "enloi", "eros", "elraina", "enelbro", "wa", "wi", "wu", "wei",
        "wenegrul", "wedhas", "wendra", "wursa", "ala", "alsidh", "a",
        "yn", "yurda", "yis", "yengwa", "yndir", "alas", "arga", "anduili",
        "sirn", "senrach", "sinildin", "senai", "sengurs", "simildin",
        "sirnash", "salagandorin", "sinelmiridh", "sanadroika", "zara",
        "zini", "xa", "xaran", "xiesa", "carac'ha", "ingol'adi", "va",
        "vinisti", "bara", "baela", "binildu" }),
    "high elven": ({ "eles", "lemui", "omenailama", "aedwse", "niurban", "ai'",
        "lanesa", "menaella", "scalan", "lienmara", "kirluin", "quaela",
        "karyach", "bragoladh", "parnd", "dullach", "khelen", "gurna", "gorgal",
        "spaena", "cam", "dura", "naur", "asca", "ami", "quella", "surna",
        "daew", "zula'a", "endrelinnadh", "zhucaradh", "burnae", "loomen",
        "sulana", "alabrindo", "nagurdal", "freni", "welana", "uvan",
        "brindi", "ooman", "dulebno", "syndwengil", "myandis", "anrobe",
        "fa'endis", "xendia", "borae", "noduli", "mendidh", " landra",
        "kaendra", "heliga", "haelar", "gondwai", "forois", "pinda",
        "pene'grae", "olomra", "iscara", "ulumir", "yendwich", "yaeri",
        "taebdhil", "taernas", "tilidal", "tengwi", "tarnwi", "romodash",
        "raenda", "rini", "ranea", "raladan", "rogloi", "rala", "romwa",
        "eleg", "eali", "ere'nda", "elgarat", "elwi", "eloqu", "emda",
        "enloi", "eros", "elraina", "enelbro", "wa", "wi", "wu", "wei",
        "wenegrul", "wedhas", "wendra", "wursa", "ala", "alsidh", "a",
        "yn", "yurda", "yis", "yengwa", "yndir", "alas", "arga", "anduili",
        "sirn", "senrach", "sinildin", "senai", "sengurs", "simildin",
        "sirnash", "sal'agandorin", "sinel'miridh", "sanadroika", "zara",
        "zini", "xa", "xaran", "xiesa", "carac'ha", "ingol'adi", "va",
        "vinisti", "bara", "baela", "binildu", "abresh", "zinfindoi",
        "memlai", "sinduro" }),
    "eledhelean": ({ "eles", "lemui", "omenailama", "aedwse", "niurban", "ai'",
        "lanesa", "menaella", "scalan", "lienmara", "kirluin", "quaela",
        "karyach", "bragoladh", "parnd", "dullach", "khelen", "gurna", "gorgal",
        "spaena", "cam", "dura", "naur", "asca", "ami", "quella", "surna",
        "daew", "zula'a", "endrelinnadh", "zhucaradh", "burnae", "loomen",
        "sulana", "alabrindo", "nagurdal", "freni", "welana", "uvan",
        "brindi", "ooman", "dulebno", "syndwengil", "myandis", "anrobe",
        "fa'endis", "xendia", "borae", "noduli", "mendidh", " landra",
        "kaendra", "heliga", "haelar", "gondwai", "forois", "pinda",
        "pene'grae", "olomra", "iscara", "ulumir", "yendwich", "yaeri",
        "taebdhil", "taernas", "tilidal", "tengwi", "tarnwi", "romodash",
        "raenda", "rini", "ranea", "raladan", "rogloi", "rala", "romwa",
        "eleg", "eali", "ere'nda", "elgarat", "elwi", "eloqu", "emda",
        "enloi", "eros", "elraina", "enelbro", "wa", "wi", "wu", "wei",
        "wenegrul", "wedhas", "wendra", "wursa", "ala", "alsidh", "a",
        "yn", "yurda", "yis", "yengwa", "yndir", "alas", "arga", "anduili",
        "sirn", "senrach", "sinildin", "senai", "sengurs", "simildin",
        "sirnash", "sal'agandorin", "sinel'miridh", "sanadroika", "zara",
        "zini", "xa", "xaran", "xiesa", "carac'ha", "ingol'adi", "va",
        "vinisti", "bara", "baela", "binildu", "abresh", "zinfindoi",
        "memlai", "sinduro" }),    
    "dwarven": ({ "ashghaz", "kemil", "abakai", "khazad", "kharad", "ai",
        "kheldach", "zurnach", "scalach", "dain", "mithra", "irot",
        "gimil", "braclarch", "eregol", "durnach", "nurin", "kherek", "gornadh",
        "sinlach", "camik", "durnaz", "zinilgor", "brandach", "amik", "quellark",
        "daew'zur", "zula'ark", "endaz'ghor", "zhurgah", "burdec", "lumik",
        "sular", "alabrin", "na'algar", "frecen", "welac", "uvach",
        "brindiz", "oomanck", "dulebnoh", "syndwenga", "mydrach", "anrobe'l",
        "fa'dhurz", "xen'qach", "bordigh", "nodulish", "mendidh", " lanach",
        "kaedruk", "heligadc", "haelark", "gondwaichik", "foroiskad", "pindal",
        "pene'uz", "olomrach", "iscarak", "ulumir'uk", "yendwich", "yaerih",
        "taebdhildh", "taernaz", "tilidak", "tendhwic", "tarnwik", "romodash",
        "fargash", "rinidh", "ranail", "raladaz", "rogloid", "ralaxak", "romwad",
        "elegzur", "ealizuk", "ere'ndar", "elgarath", "elwin", "eloqun", "emda",
        "enloi'khek", "eros'qua", "elrainwik", "enelbrog", "w'ig", "widh", "wuz", "wei'rik",
        "wenegrul", "wedhas'khed", "wendrac", "wursak", "ala'khin", "alsidh", "a",
        "khesurg", "yu'khes", "yis'nach", "ye'azak", "fidgur", "alaz", "argak", "andich",
        "sirn", "senrach", "sina'din", "senaiz", "sengurc", "simildine",
        "sirnash", "sal'agdorin", "sinel'miridh", "sanadzahr", "zarasr",
        "zinils", "xazsh", "xaranc", "xiesal", "carac'ha", "ingol'adiz", "va'rech",
        "vinistizhum", "baramur", "baelarum", "binilzurum", "abresh'ka", "zinfin'zhek",
        "memlaitum", "sinurghum" }),
    "orcish": ({ "muzr'kh", "zhu'ch", "gal'larc", "gha'sh", "sarxiz", "zinbrik",
        "gar'gur'gin", "gir", "ghiz", "zik", "nar", "ghaz", "kij", "jin", "burzik",
        "zim'rid", "g'lar", "ghil", "kirl", "nizh", "cizra", "zerdhiw", "zhen",
        "gol", "gul", "gimik", "lizik", "onz'dha", "gre'mik", "piz'nik", "lorgh",
        "wak", "wizij", "jemes", "varg'huz", "burz", "zurmis", "valk", "vrik",
        "bimiz", "zhrk", "zcs", "kdz'ak", "gurni'z", "fil'zhek", "ghim'zak",
        "curz'uk", "zamik", "zurnuk", "zibil", "laki", "larz", "lak'as", "poluk",
        "wenz'i'ik", "wi", "az", "xu", "bormuk", "kadugh", "gurfak", "rulik",
        "rinu'dhuk", "durghaz", "sirdh", "sin'gza", "zhatar", "va'zhu", "cuk",
        "xu'mik", "al'zagh", "fhed'nuk", "fachgu", "lin'kir", "opoz", "bulz",
        "niz'naduz", "hi'zhuk", "li", "ja", "hurz", "burz", "durz", "wurz", "wuk",
        "zimbor", "az'luk", "surga", "wul'ghar", "ere'luk", "yuk", "yuk'ya",
        "fa'ghal", "ghul", "durz'rich", "murzum", "mruk", "dridh", "arzum", "ilgash",
        "wilizor", "zemelith", "sig'dir", "zhcar", "z'arl", "fizuk", "cesuk",
        "biruz", "tilxudh", "xirzadh", "xi'ini'goth", "zamir", "fih", "hidh", 
        "melik", "dhurzu", "bulgz", "ludz", "wenzhik", "oroch", "bimip", "zar",
        "pimil", "lardash", "az'gash", "vurmudh", "lana'tan'bazor", "hizil",
        "miz'gara'sh", "shicdh", "jal'zhek", "gam'id", "zurbul"
    }),
    "endurghul": ({ "muzruh", "zhuaich", "galilarc", "ghaish", "sarxi", "zinbrik",
        "garaguregin", "gir", "ghiz", "zik", "nar", "ghaz", "kij", "jin", "burzik",
        "zimurid", "galar", "ghil", "kirl", "nizh", "cizra", "zerdhiw", "zhen",
        "gol", "gul", "gimik", "lizik", "onz'dha", "greimik", "pizanik", "lorgh",
        "wak", "wizij", "jemes", "varg'huz", "burz", "zurmis", "valk", "vrik",
        "bimiz", "zhrk", "zcs", "kdz'ak", "gurni'z", "fil'zhek", "ghim'zak",
        "curz'uk", "zamik", "zurnuk", "zibil", "laki", "larz", "lak'as", "poluk",
        "wenz'i'ik", "wi", "az", "xu", "bormuk", "kadugh", "gurfak", "rulik",
        "rinu'dhuk", "durghaz", "sirdh", "sin'gza", "zhatar", "va'zhu", "cuk",
        "xu'mik", "al'zagh", "fhed'nuk", "fachgu", "lin'kir", "opoz", "bulz",
        "niz'naduz", "hi'zhuk", "li", "ja", "hurz", "burz", "durz", "wurz", "wuk",
        "zimbor", "az'luk", "surga", "wul'ghar", "ere'luk", "yuk", "yuk'ya",
        "fa'ghal", "ghul", "durz'rich", "murzum", "mruk", "dridh", "arzum", "ilgash",
        "wilizor", "zemelith", "sig'dir", "zhcar", "z'arl", "fizuk", "cesuk",
        "biruz", "tilxudh", "xirzadh", "xi'ini'goth", "zamir", "fih", "hidh", 
        "melik", "dhurzu", "bulgz", "ludz", "wenzhik", "oroch", "bimip", "zar",
        "pimil", "lardash", "az'gash", "vurmudh", "lana", "tan", "bazor", "hizil",
        "miz'gara'sh", "shicdh", "jal'zhek", "gam'id", "zurbul"
    }),
    "andurathi": ({ "muzruh", "zhuaich", "galilarc", "ghaish", "sarxi", "zinbrik",
        "garaguregin", "gir", "ghiz", "zik", "nar", "ghaz", "kij", "jin", "burzik",
        "zimurid", "galar", "ghil", "kirl", "nizh", "cizra", "zerdhiw", "zhen",
        "gol", "gul", "gimik", "lizik", "onz'dha", "greimik", "pizanik", "lorgh",
        "wak", "wizij", "jemes", "varg'huz", "burz", "zurmis", "valk", "vrik",
        "bimiz", "zhrk", "zcs", "kdz'ak", "gurni'z", "fil'zhek", "ghim'zak",
        "curz'uk", "zamik", "zurnuk", "zibil", "laki", "larz", "lak'as", "poluk",
        "wenz'i'ik", "wi", "az", "xu", "bormuk", "kadugh", "gurfak", "rulik",
        "rinu'dhuk", "durghaz", "sirdh", "sin'gza", "zhatar", "va'zhu", "cuk",
        "xu'mik", "al'zagh", "fhed'nuk", "fachgu", "lin'kir", "opoz", "bulz",
        "niz'naduz", "hi'zhuk", "li", "ja", "hurz", "burz", "durz", "wurz", "wuk",
        "zimbor", "az'luk", "surga", "wul'ghar", "ere'luk", "yuk", "yuk'ya",
        "fa'ghal", "ghul", "durz'rich", "murzum", "mruk", "dridh", "arzum", "ilgash",
        "wilizor", "zemelith", "sig'dir", "zhcar", "z'arl", "fizuk", "cesuk",
        "biruz", "tilxudh", "xirzadh", "xi'ini'goth", "zamir", "fih", "hidh", 
        "melik", "dhurzu", "bulgz", "ludz", "wenzhik", "oroch", "bimip", "zar",
        "pimil", "lardash", "az'gash", "vurmudh", "lana", "tan", "bazor", "hizil",
        "miz'gara'sh", "shicdh", "jal'zhek", "gam'id", "zurbul"
    }),
    "tirnosti": ({ "tama", "on", "todella", "siisti", "viesti", "omalla", 
        "kielellani", "ja", "sita", "tulee", "kaytta", "erittain", "huolellisesti",
        "joten", "karpalo", "myrtti", "pureskella", "purenta", "nauris", "nyt",
        "hamahakki", "housut", "lama", "merkki", "laventeli", "paperi", "ja",
        "kanan", "sika", "lehma", "hevonen", "miekka", "aita", "karitsan",
        "rhwbio", "difyr", "gwarchod", "gwneud iawn", "yn daclus", "grasus",
        "addasadwy", "pwysau", "cofnodwch", "grym", "yn fywiog", "gludiog",
        "yn anodd", "yn wyliadwrus", "heddwch", "yn ddiangen", "profiad", "derbyniol",
        "vuohi", "karkea", "ihmiset", "suolla", "lyhty", "purppura", "oranssi",
        "apina", "kasine", "paita", "kaunis", "kuminauha", "kissa", "koira",
        "kettu", "ajokoira", "susi", "lumi", "poyta", "laskuri", "limada",
        "satunnainen", "verbi", "tuomita", "happo", "ankkuri", "kuollut",
        "silta", "joki", "kyyhkynen", "kotka", "mayra", "orava", "kilpi",
        "tuuletin", "ikava", "kumi", "uutuus", "kohde", "orkki", "menninkainen",
        "lohikarme", "ovi", "seepra", "sana", "kupari", "kulta", "hopea",
        "kainalo", "mutteri", "tuoli", "talo", "linna", "perhonen", "koi",
        "lumikko", "lumimies", "vuono", "polvi", "purgi", "hai", "huono"
    }),
    "hillgarathi": ({ "caniataol", "yn dderbyniol", "squeal", "blwch", "llym",
        "brawd", "drawaya", "moethus", "swyddfa", "adeiladu", "yn ol pob tebyg",
        "galluog", "poeth", "esgus", "tryciau", "addasiad", "chwerw", "chwiorydd",
        "dosbarthus", "wyau", "braich", "ciwb", "cryfhau", "sock", "gwenyn",
        "rhwbio", "difyr", "gwarchod", "gwneud iawn", "yn daclus", "grasus",
        "addasadwy", "pwysau", "cofnodwch", "grym", "yn fywiog", "gludiog",
        "yn anodd", "yn wyliadwrus", "heddwch", "yn ddiangen", "profiad", "derbyniol",
        "colled", "pellter", "cefnogaeth", "anodd", "atgoffa", "paltria",
        "anghyfartal", "meddu", "darganfyddwch", "adran", "bownsio", "carchar",
        "anhygoel", "eglwys", "llawen", "lladd", "ysgrifennydd", "elastig",
        "enw", "gwenwyn", "gwn", "menyn", "tri", "braidd", "yn ddiflas", 
        "camdriniol", "effeithlon", "bwysig", "cadw", "profi", "siop", 
        "ar fwrdd", "ymlaen", "llafurwr", "dur", "fforddio", "llawr", 
        "daear", "yn amheus", "hop", "cleis", "awyrennau", "effeithlon", "casglu",
        "gwelodd", "ceffyl", "ystafell", "bom", "cyffredin", "blodeuog",
        "llyfr", "arsylwi", "amheuaeth", "daeargryn", "glud", "crib", "clirio",
        "mwg", "niwl", "byth", "trwyn", "gwerthfawr", "aros", "stopio", "siarad",
        "gwerthfawr", "atgyweiria", "anwastad", "soffa", "chwaethus", "rhannu",
        "yn golygu", "niweidiol", "ofn", "amwys", "ysbryd", "yn poeni",
        "heb ei ddefnyddio", "cynhyrchu", "twrci", "hwylio", "gwarant"
    }),
    "draconid": ({ "muzruh", "zhuaich", "galilarc", "ghaish", "sarxi", "zinbrik",
        "garaguregin", "gir", "ghiz", "zik", "nar", "ghaz", "kij", "jin", "burzik",
        "zimurid", "galar", "ghil", "kirl", "nizh", "cizra", "zerdhiw", "zhen",
        "gol", "gul", "gimik", "lizik", "onz'dha", "greimik", "pizanik", "lorgh",
        "wak", "wizij", "jemes", "varg'huz", "burz", "zurmis", "valk", "vrik",
        "bimiz", "zhrk", "zcs", "kdz'ak", "gurni'z", "fil'zhek", "ghim'zak",
        "curz'uk", "zamik", "zurnuk", "zibil", "laki", "larz", "lak'as", "poluk",
        "wenz'i'ik", "wi", "az", "xu", "bormuk", "kadugh", "gurfak", "rulik",
        "rinu'dhuk", "durghaz", "sirdh", "sin'gza", "zhatar", "va'zhu", "cuk",
        "xu'mik", "al'zagh", "fhed'nuk", "fachgu", "lin'kir", "opoz", "bulz",
        "niz'naduz", "hi'zhuk", "li", "ja", "hurz", "burz", "durz", "wurz", "wuk",
        "zimbor", "az'luk", "surga", "wul'ghar", "ere'luk", "yuk", "yuk'ya",
        "fa'ghal", "ghul", "durz'rich", "murzum", "mruk", "dridh", "arzum", "ilgash",
        "wilizor", "zemelith", "sig'dir", "zhcar", "z'arl", "fizuk", "cesuk",
        "biruz", "tilxudh", "xirzadh", "xi'ini'goth", "zamir", "fih", "hidh", 
        "melik", "dhurzu", "bulgz", "ludz", "wenzhik", "oroch", "bimip", "zar",
        "pimil", "lardash", "az'gash", "vurmudh", "lana", "tan", "bazor", "hizil",
        "miz'gara'sh", "shicdh", "jal'zhek", "gam'id", "zurbul"
    }),
    "menadrosti": ({ "dozvoljeno", "prihvatljivo", "skaal", "brate", "crtak",
        "luksuzno", "ured", "zgrade", "odvratno", "zdravo", "sposoban", "vruce",
        "izgovor", "kamioni", "podesavanje", "gorko", "sestre", "jaja", "ruka",
        "cub", "jacati", "carapa", "rub", "zabavite se", "strazar", "improvizacija",
        "uredno", "graciozno", "prilagodljiv", "tezina", "zapis", "sila", "zivahno",
        "lepljiva", "glomazno", "oprezni", "mir", "suvisan", "iskustvo", "receptivna",
        "gubitak", "razdaljina", "podrska", "tesko", "podsjetite", "bezvrijedno",
        "nejednako", "posedovati", "otkriti", "divizija", "odskociti", "zatvora",
        "grozno", "crkva", "neuredan", "ubij", "sekretar", "elastican", "ime",
        "otrov", "pistolj", "maslac", "tri", "zbunjeno", "uvredljiv", "efikasan",
        "bitan", "sacuvati", "testirano", "prodavnica", "na brodu", "napred",
        "radnik", "celik", "priusyiti", "pod", "zemlja", "upitno", "modrica",
        "aviona", "efikasan", "okupljati", "blesavo", "vidio", "konj", "soba",
        "bomba", "upucen", "cvetno", "knjiga", "posmatrajte", "sumnja", "zemljotres",
        "ljepilo", "krevetac", "magla", "amuck", "nos", "dragocen", "cekaj", "stani",
        "pricajte", "vredno", "popravi", "neravnomjeran", "sofa", "cudan", "podeliti",
        "znaci", "stetno", "uplasen", "dvosmislen", "duh", "zabrinuto", "neiskoristeno",
        "proizvesti", "curka", "plovi", "garancija"
    }),
    "common": ({ "caniataol", "yn dderbyniol", "squeal", "blwch", "llym",
        "brawd", "drawaya", "moethus", "swyddfa", "adeiladu", "yn ol pob tebyg",
        "galluog", "poeth", "esgus", "tryciau", "addasiad", "chwerw", "chwiorydd",
        "dosbarthus", "wyau", "braich", "ciwb", "cryfhau", "sock", "gwenyn",
        "rhwbio", "difyr", "gwarchod", "gwneud iawn", "yn daclus", "grasus",
        "addasadwy", "pwysau", "cofnodwch", "grym", "yn fywiog", "gludiog",
        "yn anodd", "yn wyliadwrus", "heddwch", "yn ddiangen", "profiad", "derbyniol",
        "colled", "pellter", "cefnogaeth", "anodd", "atgoffa", "paltria",
        "anghyfartal", "meddu", "darganfyddwch", "adran", "bownsio", "carchar",
        "anhygoel", "eglwys", "llawen", "lladd", "ysgrifennydd", "elastig",
        "enw", "gwenwyn", "gwn", "menyn", "tri", "braidd", "yn ddiflas", 
        "camdriniol", "effeithlon", "bwysig", "cadw", "profi", "siop", 
        "ar fwrdd", "ymlaen", "llafurwr", "dur", "fforddio", "llawr", 
        "daear", "yn amheus", "hop", "cleis", "awyrennau", "effeithlon", "casglu",
        "gwelodd", "ceffyl", "ystafell", "bom", "cyffredin", "blodeuog",
        "llyfr", "arsylwi", "amheuaeth", "daeargryn", "glud", "crib", "clirio",
        "mwg", "niwl", "byth", "trwyn", "gwerthfawr", "aros", "stopio", "siarad",
        "gwerthfawr", "atgyweiria", "anwastad", "soffa", "chwaethus", "rhannu",
        "yn golygu", "niweidiol", "ofn", "amwys", "ysbryd", "yn poeni",
        "heb ei ddefnyddio", "cynhyrchu", "twrci", "hwylio", "gwarant"
    }),

]);

/////////////////////////////////////////////////////////////////////////////
private nomask string garbleMessage(string language, int skillLevel, string message)
{
    string ret = message;
    if (skillLevel < 10)
    {
        string *newMessage = explode(ret, " ");
        for (int i = 0; i < sizeof(newMessage); i++)
        {
            if ((skillLevel == 0) || ((i % 10) >= skillLevel))
            {
                int newWordIndex = random(sizeof(languages[language]));
                newMessage[i] = languages[language][newWordIndex];
            }
        }
        ret = implode(newMessage, " ");
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string applyLanguageSkillToMessage(string language,
    string message, int skillLevel)
{
    string revisedMessage = message;

    if (!member(languages, language))
    {
        language = "garblish";
    }
 
    return capitalize(garbleMessage(language, skillLevel, revisedMessage));
}

/////////////////////////////////////////////////////////////////////////////
public nomask string applyLanguageSkillToReceivedMessage(string language,
    string message, object target, object initiator)
{
    string revisedMessage = message;
    if (objectp(target) && objectp(initiator))
    {
        if (!member(languages, language))
        {
            language = "garblish";
        }
        revisedMessage = garbleMessage(language,
            target->getSkill(language), revisedMessage);

        revisedMessage = garbleMessage("garblish",
            initiator->getSkill(language), revisedMessage);
    }
    return capitalize(revisedMessage);
}

/////////////////////////////////////////////////////////////////////////////
public nomask string getSpokenLanguage(string language, object initiator)
{
    string ret = "";
    if (objectp(initiator))
    {
        switch (initiator->getSkill(language))
        {
            case 0:
            {
                ret = "complete gibberish";
                break;
            }
            case 1..3:
            {
                ret = "gibberish with a hint of " + language;
                break;
            }
            case 4..7:
            {
                ret = "broken " + language;
                break;
            }
            case 8..9:
            {
                ret = "slightly broken " + language;
                break;
            }
            default:
            {
                ret = language;
            }
        }
    }
    return ret;
}
