//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef henchmanNames_h
#define henchmanNames_h

private string *maleNames = ({
    "Aradan", "Aramed", "Ardenel", "Aglaradan", "Alarac", "Alerik", "Alberich", 
    "Aidan", "Angus", "Ahearn", "Angus", "Arthur", "Bain", "Baird", "Balfour",
    "Beathan", "Boyd", "Beren", "Bregor", "Berenar", "Brennan", "Brendan", 
    "Bregloas", "Caden", "Caedmon", "Cael", "Carlin", "Carrick", "Carson",
    "Celath", "Chargon", "Cian", "Curthan", "Collin", "Colvin", "Corbin",
    "Cowan", "Derek", "Daenor", "Darrick", "Donald", "Devin", "Duran", "Duor",
    "Dougan", "Drystan", "Duncan", "Eagnor", "Eachann", "Edan", "Egan", "Eradin",
    "Ergal", "Ewan", "Ewing", "Faolan", "Faerdil", "Fergus", "Fingal", "Finn",
    "Flynn", "Gainor", "Gerak", "Geren", "Galvin", "Glynn", "Graeden", "Hagan",
    "Herach", "Haeron", "Huran", "Herumor", "Huradan", "Helcaron", "Helfast",
    "Helmuth", "Haeradin", "Kaden", "Kael", "Keron", "Kagan", "Karsten", 
    "Kaelan", "Kerak", "Kellen", "Kenneth", "Kevin", "Kiernan", "Kieron",
    "Kyle", "Leith", "Lognar", "Lorien", "Lorren", "Les", "Loran", "Lorcan",
    "Laeron", "Laradin", "Marach", "Malfen", "Marrick", "Macaeth", "Mallen",
    "Halgaladh", "Harold", "Maxwell", "Murray", "Malcolm", "Neil", "Nagrath",
    "Nelson", "Nigel", "Niall", "Nolan", "Norm", "Oredh", "Orathon", "Oisin",
    "Ormond", "Owen", "Quill", "Quinlan", "Quillan", "Rey", "Roan", "Riordan",
    "Relach", "Raenor", "Ralagon", "Rodan", "Ronin", "Rory", "Saoirse", "Serach",
    "Seradin", "Seranel", "Saeron", "Saradil", "Tarack", "Taeron", "Teagan",
    "Tevin", "Turan", "Tuonath", "Tiernan", "Torin", "Tristan", "Ulreth", "Ulgor",
    "Ueran", "Uinar", "Vargath", "Vaeron", "Verak", "Valroth", "Vaerdan",
    "Verach", "Vorgal", "Volrith", "Thomas", "Vaernor", "Warak", "Waeron", "Wallan",
    "Willhelm", "Warnach", "Werdhel", "Wyan", "Winfreth", "Wigandh", "Yrchvin",
    "Yrgal", "Yaradhel", "Yendrath", "Vendrath", "Yenegal", "Zurdhen", "Zuredh",
    "Zalden", "Arawn", "Jerac", "Juron", "Jerith", "Jorgil", "Jordath", "Jorath",
    "Joren", "Jordan", "Irich", "Erich", "Olric", "Osric", "Oren", "Oranal"
});

private string *femaleNames = ({
    "Aelinwen", "Alanna", "Ayana", "Aegrid", "Aeryn", "Aewyn", "Alanwyn", 
    "Arissa", "Anna", "Alandria", "Arandwyn", "Baerwyn", "Balanna", "Berwyn",
    "Baeradhel", "Binadwen", "Brianna", "Bulwyn", "Calaya", "Caryn", "Caelana",
    "Curiene", "Caewyn", "Coriele", "Caedhwyn", "Branwyn", "Brenna", "Bryn",
    "Cienne", "Aranwyn", "Adaena", "Aedana", "Alyssa", "Curana", "Culiene",
    "Duna", "Danessa", "Duriel", "Dolwyn", "Donessa", "Delana", "Dorina", "Ellen",
    "Erin", "Earwyn", "Eadana", "Elena", "Elwyth", "Fionah", "Fiorwyn", "Faerna",
    "Fulryth", "Ferah", "Galawyn", "Galana", "Gilmyth", "Galnara", "Gwydhneth",
    "Gwen", "Guiriel", "Helen", "Haleth", "Herah", "Helana", "Hilgrid", "Hurwyth",
    "Karen", "Ilya", "Ilreth", "Ilana", "Ilaya", "Iriel", "Inawin", "Idwyn",
    "Janeth", "Aaliyah", "Abigail", "Ada", "Adele", "Adelita", "Adina", "Adria",
    "Adrianna", "Adrianne", "Adrienn", "Agata", "Agneta", "Agnes", "Aileen", 
    "Alisa", "Aja", "Alecta", "Ailese", "Alessa", "Alfhild", "Alexa", "Alice",
    "Amara", "Ianthe", "Jadeth", "Jaden", "Kaerin", "Kaelan", "Kai", "Kei",
    "Kaia", "Karina", "Katrin", "Correnne", "Kaja", "Kaedhwen", "Laia", 
    "Lacey", "Lanessa", "Laiwyth", "Liliene", "Lenwyth", "Layana", "Loriene",
    "Lyllith", "Lya", "Lara", "Larissa", "Lark", "Laurel", "Lauren", "Leah",
    "Lavonne", "Layla", "Lorwyn", "Maerin", "Marwyn", "Melwyn", "Melweth",
    "Madalyn", "Madwyn", "Melian", "Morwen", "Morwyn", "Morwyth", "Milana",
    "Miriel", "Mariel", "Marien", "Marina", "Cordelia", "Merwyn", "Naela",
    "Narissa", "Nienwyn", "Nelina", "Nurina", "Nulwyth", "Olaina", "Oria",
    "Ophelia", "Orana", "Paena", "Parwyn", "Paula", "Petra", "Phaeda",
    "Phoebe", "Quiana", "Querida", "Rian", "Rhiannon", "Rhia", "Renae", 
    "Rhenwyn", "Rachel", "Raine", "Rae", "Rayen", "Rayna", "Rochelle",
    "Rolaweth", "Salwen", "Saffron", "Safaya", "Sarawyn", "Serweth",
    "Saerweth", "Shaywyn", "Sirena", "Siobhan", "Selena", "Siri", "Skyleigh",
    "Sonia", "Sora", "Sorcha", "Selweth", "Siriel", "Sorana", "Taina",
    "Talitha", "Telwyn", "Tirwyn", "Tienna", "Talia", "Tania", "Tara",
    "Terana", "Hope", "Ulwyn", "Uinya", "Vala", "Vaira", "Varana", "Verwyn",
    "Vulweth", "Wrena", "Walreth", "Winreth", "Winara", "Wranya", "Wynne",
    "Xanrda", "Xanthe", "Xenia", "Yasania", "Yara", "Yorina", "Zaira",
    "Zara"
});

private string *familyNames = ({
    "Arthellyn", "Argalen", "Aelfan", "Aladain", "Eznaruin", "Ghandur",
    "Eralkidh", "Hrondil", "Eolach", "Kirin", "Evendim", "Dalthren", 
    "Belathon", "Anduradan", "Belectar", "Marannuminas", "Gundil", "Denlap",
    "Karendur", "Gundil", "Galdur", "Erator", "Aelgil", "Valamar",
    "Endur", "Hador", "Urdhan", "Oeldhen", "Llenwych"
});

#endif