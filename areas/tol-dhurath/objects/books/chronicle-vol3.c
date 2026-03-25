//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/book.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "A Chronicle of the Eastern Lands, Volume III");
    set("short", "A worn leather-bound chronicle, Volume III");
    set("title", "A Chronicle of the Eastern Lands, Volume III: "
        "The Long Twilight");
    set("aliases", ({ "chronicle", "volume iii", "volume 3", "book",
        "chronicle volume iii", "chronicle volume 3" }));
    set("long", "A thick tome bound in cracked brown leather, the "
        "third in a series. The spine reads: 'A Chronicle of the "
        "Eastern Lands, Volume III: The Long Twilight.' Several "
        "pages bear watermarks, as though the book once survived "
        "a flood.");

    addChapter("The Line of Kings",
        "Year 667: Erestel becomes king of Eledhel as Ar-Telcontar.\n\n"
        "Year 683: Maglandil becomes king of Hillgarath.\n\n"
        "Year 708: Plague sweeps through the lands. Lands south of "
        "Linmir are the most heavily hit.\n\n"
        "Year 806: Elandur assumes the throne of Eneldhor.\n\n"
        "Year 821: Armadil assumes the throne of Eledhel.\n\n"
        "Year 827: Maunladir assumes the throne of Hillgarath.\n\n"
        "Year 859: Celebgaer and Gildaer cede from Kharand, forming "
        "the nation of Lonisiach. Kharand expels Bryleth and "
        "fragments into many autonomous city-states.\n\n"
        "[A marginal note: 'Bryleth expelled. She had reigned "
        "unchallenged for 544 years. No mortal woman could accomplish "
        "this. The Scions are certain she is something far more "
        "dangerous than a mere queen.']\n\n"
        "Year 943: Maunladir slain in battle with orcs. Eredhur "
        "assumes the throne of Hillgarath.\n\n"
        "Year 946: Eredhur slain. Balathin assumes the throne.\n\n"
        "Year 978: Arlenur assumes the throne of Eledhel.\n\n"
        "Year 1003: Mirost calls upon the alliance for aid against "
        "an orcish incursion. Hillgarath, Linmir, and Eledhel "
        "answer the call.\n\n"
        "Year 1014: Ghurzhaleb, the mighty fortress of the orcs, "
        "is destroyed.\n\n"
        "Year 1089: Balgamir assumes the throne of Hillgarath.\n\n"
        "Year 1138: Ardenach assumes the throne of Eledhel.");

    addChapter("The Dwarven League and Argloth the Wise",
        "Year 1204: The League of Dwarven Nations is founded. "
        "Emissaries of Durin XI Stonehelm of Erebor, Gloin IV of "
        "Aglarond, and Khazurin of Khazurath meet with Azgurin IX "
        "in Mirost.\n\n"
        "Year 1218: A high elf known as Argloth the Wise is "
        "gifted the Tower of Dhuras by King Balgamir and given "
        "the title of Governor of Dhuras.\n\n"
        "[A marginal note in a proud hand: 'Our order's founding. "
        "Argloth was a scholar of immense learning, a wizard of "
        "great power, and in those early days, a man of deep "
        "wisdom. What he became later does not diminish what he "
        "built here.']\n\n"
        "Year 1219: Balgamir falls victim to a mysterious ailment. "
        "The ranks of the Werric Knighthood and aristocracy are "
        "severely depleted. Nienwen becomes queen of Hillgarath.\n\n"
        "Year 1295: Aramed assumes the throne of Eledhel.\n\n"
        "Year 1356: Her son now in his prime, Nienwen abdicates. "
        "Eneldin assumes the throne of Hillgarath.");

    addChapter("The Wars of Andurath",
        "Year 1412: Andurath attacks the nations of the alliance. "
        "Eneldin slain in the Battle of Helcarion. Eneldin II "
        "assumes the throne of Hillgarath.\n\n"
        "Year 1438: Aranadur assumes the throne of Eledhel.\n\n"
        "Year 1491: Eneldin II slain in battle with Andurath. "
        "Palandil assumes the throne of Hillgarath.\n\n"
        "Year 1578: Argaldin assumes the throne of Eledhel.\n\n"
        "Year 1608: Palandil II assumes the throne of Hillgarath.\n\n"
        "Year 1668: Argaldin slain in battle with orcs. Ardanel "
        "assumes the throne of Eledhel.");

    addChapter("The Keepers of the Night",
        "Year 1689: The Keepers of the Night first appear. Their "
        "origins are shrouded in mystery, but they worship a dark "
        "power and spread corruption wherever they take root.\n\n"
        "Year 1691: Argloth, concerned over rumors of unnatural "
        "evil occurrences, musters the forces of Dhuras and falls "
        "upon the stronghold of the Keepers of the Night. He takes "
        "the tower of Zhardeg for his own.\n\n"
        "Year 1692: The dragon Ilzhagash issues from Utumnadh and "
        "attacks Mirost. The dwarves slay the beast. Later that "
        "year, Sylthasis, another dragon, issues from Utumnadh.\n\n"
        "Year 1693: Arnost destroyed by Sylthasis. Mirost falls "
        "to the dragon. The remnants of the land seek protection "
        "in Hillgarath. In time, most of the survivors swell the "
        "ranks of Khazurath.\n\n"
        "Year 1698: Arandahir assumes the throne of Eledhel.\n\n"
        "Year 1704: Eldarel founded.\n\n"
        "Year 1714: Emandil assumes the throne of Hillgarath.");

    addChapter("The Tragedy of Argloth",
        "Year 1765: Arandahir slain in battle with orcs near the "
        "ruins of Mirost. Arienwen becomes the queen of Eledhel.\n\n"
        "Year 1797: Andurath attacks Helcarion. Emandil leads his "
        "armies against Andurath. Arienwen aids the venture.\n\n"
        "Year 1802: Urfach usurps the throne of Emandil and slays "
        "the queen and all but Emandil's son. Emandil and his "
        "Werric Knights break from the battle of Helcarion and "
        "return. For the next fourteen years, Hillgarath is "
        "engaged in a bloody civil war.\n\n"
        "Year 1803: Eledhel scores an unexpected victory over "
        "Andurath.\n\n"
        "Year 1806: Emandil slain. Calendil his son assumes the "
        "title of king in exile.\n\n"
        "Year 1807: Calendil, at the advice of Daedrun, requests "
        "sanctuary in Eledhel and is granted aid by Queen Arienwen. "
        "She pledges her armies to his cause.\n\n"
        "Year 1809: King Calendil of Hillgarath weds Elmariel, "
        "daughter of Queen Arienwen of Eledhel.\n\n"
        "Year 1816: Urfach slain in battle with Calendil. The "
        "kingship is restored.\n\n"
        "Year 1843: Argloth tests his power against Sylthasis. "
        "His army is utterly destroyed, though he survives. At "
        "this point, a distinct change in his personality can be "
        "seen. He becomes consumed with the desire for power so "
        "that he can destroy the dragon.\n\n"
        "[A marginal note in an anguished hand: 'Here begins our "
        "shame. What drove him to such obsession? The dragon, "
        "yes, but something else as well. Some of the elder "
        "brothers whispered that Argloth had found something in "
        "Zhardeg - something that the Keepers had been guarding. "
        "Something that whispered to him.']");

    addChapter("The Fall of Argloth and the Tainting of Mirost",
        "Year 1871: Arienwen passes. Arcalmir assumes the throne "
        "of Eledhel.\n\n"
        "Year 1877: Arcalmir and his wife are ambushed and slain "
        "by orcs. Eledhel requests that rulership pass to Elmariel. "
        "She refuses amid concerns of merging the nations. She "
        "suggests her second son Esteldurin, who is coronated as "
        "Arvadan, king of Eledhel.\n\n"
        "Year 1888: Argloth again attempts to slay Sylthasis. "
        "Again, he fails.\n\n"
        "Year 1893: Andurath erupts in civil war. Relative peace "
        "from that sector begins, lasting three hundred years.\n\n"
        "Year 1936: Calendil abdicates the throne of Hillgarath "
        "to his son Emendacil.\n\n"
        "Year 1964: Argloth slays Sylthasis and assumes control of "
        "Mirost. The dwarves are outraged. Hillgarath and the "
        "dwarves march on Argloth.\n\n"
        "Year 1965: The Battle of Mirost is waged by the Werric "
        "Knights and remnants of the former Mirost population. "
        "Argloth has enlisted orcs into his service and, more "
        "sinister, controls the corpse of Sylthasis and many of "
        "the dwarves who had been slain when Mirost was lost. "
        "Though Argloth is slain and the Werrics and dwarves "
        "victorious, Mirost is abandoned, for the dwarves acutely "
        "sense that the halls are tainted by evil.\n\n"
        "[A final marginal note: 'With Argloth's death, the "
        "Scions of Dhuras lost their founder and their purpose "
        "became preservation rather than pursuit of power. We "
        "maintain the tower and its libraries as a warning: "
        "the road to ruin is paved with noble intentions.']");
}
