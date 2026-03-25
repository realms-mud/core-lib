//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/book.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "A Chronicle of the Eastern Lands, Volume I");
    set("short", "A worn leather-bound chronicle, Volume I");
    set("title", "A Chronicle of the Eastern Lands, Volume I: The Age of Restoration");
    set("aliases", ({ "chronicle", "volume i", "volume 1",
        "chronicle volume i", "chronicle volume 1", "book",
        "chronicle of the eastern lands" }));
    set("long", "A thick tome bound in cracked brown leather. The "
        "spine bears the faded gilt lettering: 'A Chronicle of the "
        "Eastern Lands, Volume I: The Age of Restoration.' The pages "
        "are yellowed but still legible, written in a careful hand "
        "with occasional marginal annotations by later scholars.");

    addChapter("The Restoration of Kingdoms",
        "Year 0: Arendor restores the kingdoms of Eneldhor and Ardain, "
        "uniting the fractured remnants of the western realms under "
        "a single crown once more.\n\n"
        "Year 16: The first expedition to the eastern lands reaches "
        "Serach. Diplomatic relations between Hillgarath and Eneldhor "
        "begin in earnest. King Ulric of Hillgarath sends his son "
        "Werra to Eneldhor as an envoy of goodwill.\n\n"
        "Year 18: Kharand, apparently not worn out from centuries of "
        "war, invades Tirnost and occupies all lands west of the Lonis "
        "River.\n\n"
        "Year 19: An alliance is forged between Kharand and Andurath. "
        "The pact gives Kharand rights to all lands north of Ered "
        "Celebdur, leaving Andurath free to conquer the lands to the "
        "south. A dark compact that would reshape the eastern world.");

    addChapter("The Mhordrath Advance",
        "Year 21: The Mhordraths of Kharand continue their relentless "
        "push eastward, crushing the kingdoms of Lonis, Rhudenost, and "
        "Calciduil. King Ulric holds the Mhordraths at bay at the Gap "
        "of Delerath, though the Kingdom of Delerath itself falls.\n\n"
        "Year 22: Delerath Keep founded by Ulric upon the ashes of "
        "the fallen kingdom, a bastion against the advancing tide.\n\n"
        "Year 23: Dor-Duilath is overrun by forces from Andurath, led "
        "by their long-standing wizard-king Dervach. The great city "
        "of Helcarion falls to Andurath.\n\n"
        "Year 27: Celebdiul and Meluin fall to Andurath.\n\n"
        "Year 28: Linmir falls to a joint attack by Kharand and "
        "Andurath. Andurath assumes control of the city.");

    addChapter("The Tide Turns",
        "Year 31: Werra returns to Hillgarath upon the death of Ulric. "
        "He institutes sweeping changes in Hillgarathian law and "
        "founds the Werric Knighthood, an order that would shape the "
        "fate of the east for millennia to come.\n\n"
        "Year 32: Delerath falls to Kharand as Andurath simultaneously "
        "launches an attack on Morthysse. Werra's eldest son Uldrich "
        "is slain in battle. Eledrost is razed by the armies of "
        "Andurath after a costly siege.\n\n"
        "Year 33: The dwarves of Mirost, led by Azgurin III, come to "
        "the aid of Hillgarath. They halt Kharand's advance at "
        "Nalgost. Meanwhile, Beldarost, Aernan, Helcardan, and "
        "Tol-Ithyl fall to the forces of Andurath.\n\n"
        "Year 34: The dwarves of Khazurath declare war on Andurath "
        "and besiege the city of Faernost.\n\n"
        "Year 37: The Werric Knights and dwarves of Mirost retake "
        "Delerath.\n\n"
        "Year 38: Werra sends a plea to King Arendor of Eneldhor "
        "requesting aid. Arendor begins preparations for war.");

    addChapter("The Great Alliance",
        "Year 39: Tol-Gelah falls to Andurath. The siege of Orothysse "
        "begins. The elves of Echorluin and Ost-yn-Thudyl declare "
        "war on Andurath. Orothysse is supplied from the sea.\n\n"
        "Year 40: The elves of Echorluin hand a devastating defeat "
        "to the navy of Andurath off the shores of Orothysse. The "
        "army of Eneldhor, led by Arendor and Eonach of Norgaard, "
        "disembarks. With Arendor travels his longtime friend and "
        "son of Halbaladh, Halgaladh.\n\n"
        "Year 41: King Surachar of Kharand is slain in battle. The "
        "army of Kharand that had occupied the land around Delerath "
        "is utterly destroyed. One of Surachar's advisors, a wizard "
        "of considerable power named Egornac, assumes command of the "
        "armies.\n\n"
        "Year 42: Egornac retakes Delerath Keep and pushes into "
        "Hillgarath as far as Dhuras Tower.\n\n"
        "[A marginal note in a different hand reads: 'Dhuras Tower "
        "- our founding place. How near we came to losing it before "
        "we ever took residence.']");

    addChapter("Victory and Its Cost",
        "Year 43: Arendor arrives at Serach with a massive army. The "
        "siege of Orothysse is broken and the forces from Andurath "
        "soundly defeated.\n\n"
        "Year 44: The combined armies of Hillgarath and her allies "
        "sweep through Hillgarath, restoring its borders. The Kingdom "
        "of Linmir is re-established. The cities of Celebdur, Meluin, "
        "Celebduil, and Uldurost are recovered and form the new "
        "nation of Meledwath.\n\n"
        "Year 45: The lands as far south as Helcarion and Duilath "
        "Keep north to the Lonis River are recovered from Andurath. "
        "Elechar declares himself king of Kirnost.\n\n"
        "Year 46: Egornac vanishes, never to be seen again. The armies "
        "of Kharand are overwhelmed. Dor-Temnost is founded with "
        "Tirnost as its capital. Lonis, Rhudenost, and Calciduil form "
        "an alliance that is to become the Kingdom of Nurenlun. The "
        "Kharand capital of Khendrus is razed. Kharand surrenders and "
        "is allowed to remain autonomous under a heavy yearly tribute "
        "to Dor-Temnost. Dervach falls in battle. King Werra is slain. "
        "Andurath collapses and falls into civil war as many countless "
        "pretenders vie for the throne. Ulric II becomes king of "
        "Hillgarath. Arendor and Eonach return to the west.");

    addChapter("The Age of Settlement",
        "Year 47: Serach becomes the first permanent settlement of "
        "Eneldhor in the east. King Ulric II gifts all lands east of "
        "River Hillgarath to Eneldhor. A group of 400 elves from "
        "Echorluin settle at Hillgarath Keep. The group consists "
        "largely of high elves and is led by one who calls himself "
        "Daedrun. Daedrun swears fealty to Ulric II and joins the "
        "Werric Knighthood.\n\n"
        "Year 49: Menadrost declares independence from Andurath.\n\n"
        "Year 53: Hirnost declares independence and requests protection "
        "from Meledwath. Caranost also declares but remains completely "
        "autonomous.\n\n"
        "Year 77: Elechar V becomes king of Dor-Temnost.\n\n"
        "Year 84: Smoke belches forth from Utumnadh. Orcs begin to "
        "multiply in the mountains surrounding it.\n\n"
        "Year 85: Orcs begin to harry the lands around Utumnadh, "
        "including the realms of Mirost and Hillgarath.\n\n"
        "Year 91: Ulric III becomes king of Hillgarath.\n\n"
        "Year 94: Ulric III slain in battle with the orcs. Melenil "
        "becomes king of Hillgarath.");

    addChapter("The Orcslayer Wars",
        "Year 106: Elonoch becomes king of Dor-Temnost. Gildaer and "
        "Celebgaer are annexed.\n\n"
        "Year 108: Orcs sack Arnost. The entire population of the "
        "city, some 240,000 souls, are slain. Their heads are sent "
        "on a barge down the Hillgarath River. Mirost and Hillgarath "
        "begin the Orcslayer Wars.\n\n"
        "Year 109: Mirost is placed under siege. Dhuras Keep is razed. "
        "Hillgarath calls on Eneldhor for aid. Serach immediately "
        "mobilizes. Arendor again prepares for war.\n\n"
        "[A marginal note: 'The first destruction of our keep. We "
        "rebuilt stronger.']\n\n"
        "Year 111: Eldarion, son of Arendor, and his longtime friend "
        "Elthoron, scion of Halbaladh's line, reach Serach.\n\n"
        "Year 112: The orcish stronghold near Utumnadh is utterly "
        "destroyed. Eldarion returns to Eneldhor.\n\n"
        "Year 114: Dor-Temnost declares war on Kharand. Uladar is "
        "annexed.\n\n"
        "Year 115: Agrendin and Kharand annexed by Dor-Temnost.\n\n"
        "Year 116: Melenil II becomes king of Hillgarath.\n\n"
        "Year 120: Arendor, King Eledhen of Eneldhor, passes. "
        "Eldarion becomes king of Ardain and Eneldhor.");
}
