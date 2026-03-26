//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/book.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "A Chronicle of the Eastern Lands, Volume II");
    set("short", "A worn leather-bound chronicle, Volume II");
    set("title", "A Chronicle of the Eastern Lands, Volume II: "
        "The Age of Empires");
    set("aliases", ({ "chronicle", "volume ii", "volume 2", "book",
        "chronicle volume ii", "chronicle volume 2" }));
    set("long", "A thick tome bound in cracked brown leather, companion "
        "to the first volume. The spine reads: 'A Chronicle of the "
        "Eastern Lands, Volume II: The Age of Empires.' The pages "
        "are brittle at the edges but the text remains clear.");

    addChapter("The Famine and Dor-Temnost's Expansion",
        "Year 121: Queen Aryne dies. A severe famine falls on the "
        "lands. Dor-Edhel is depopulated and the remnants annexed "
        "by Dor-Temnost.\n\n"
        "Year 153: Ulric IV becomes king of Hillgarath.\n\n"
        "Year 155: Nernem, Eslarach, Endurghul, and Zhendulach "
        "annexed by Dor-Temnost.\n\n"
        "Year 158: Rhundaur annexed by Dor-Temnost.\n\n"
        "Year 171: Khendazach annexed by Dor-Temnost.\n\n"
        "Year 173: Elonach slain in battle. Elonoch II becomes king "
        "of Dor-Temnost. He is said to look exactly like his father, "
        "though he proves to be a sadistic and cruel man. The lands "
        "under his domain suffer greatly.\n\n"
        "Year 177: Enedloth declares independence amid rising unrest. "
        "Elonoch II squashes the rebellion, razes the city, and puts "
        "everyone - man, woman, and child - to the knife. The "
        "remaining cities of the empire fall in line.");

    addChapter("Queen Ainderie and the Uneasy Peace",
        "Year 187: Ulfred becomes king of Hillgarath.\n\n"
        "Year 193: The city of Dor-Lonis is occupied by Dor-Temnost. "
        "The Werric Knights in nearby Delerath Keep send a warning. "
        "Elonoch II declares he has no intention of encroaching east "
        "of the Lonis River and withdraws.\n\n"
        "Year 194: Hillgarath is ravaged by plague. Ulfred dies, as "
        "do his three sons. Ainderie becomes the first ruling queen "
        "of Hillgarath at the age of six. Amid unrest, Daedrun "
        "declares as regent.\n\n"
        "Year 207: Ainderie weds Curudil, one of Daedrun's high elf "
        "companions. Curudil refuses the rightful power of king, "
        "deferring all rulership to his wife.\n\n"
        "Year 212: Kirnost and Meledwath form an alliance amid fears "
        "of Dor-Temnost's expansion.\n\n"
        "Year 213: Hillgarath joins the alliance. Linmir and Nurenlun "
        "join later that year. Dor-Temnost sends a warning.\n\n"
        "Year 215: Dor-Temnost builds many forts along the Lonis "
        "River. The alliance matches these moves.\n\n"
        "Year 216: Mirost joins the alliance at the request of Queen "
        "Ainderie. Eldarion reinforces Serach as war looks inevitable. "
        "He enlists the aid of the men of Dale and dwarves of Ekalbor "
        "and the Iron Hills.\n\n"
        "Year 218: Ainderie personally leads her armies into battle "
        "as Dor-Lonis is invaded by Elonoch II. He is soundly defeated "
        "and aggression ends before full-scale war erupts. The uneasy "
        "'peace' begins, lasting the next 90 years.\n\n"
        "Year 249: Elonoch III declares himself emperor of Dor-Temnost. "
        "The only thing that can be said of him is that he lacked his "
        "father's wisdom and was in all respects a good deal worse.\n\n"
        "Year 287: Ainderie passes at the age of 99, having ruled for "
        "93 years. Curudil, grief-stricken, passes into the west. "
        "Eldarendil, their eldest son, assumes the throne.");

    addChapter("War with Dor-Temnost and the Founding of Eledhel",
        "Year 308: Elonoch III declares war on the alliance, "
        "simultaneously attacking on both his eastern and western "
        "fronts. The cities of Dor-Lonis and Carandur fall.\n\n"
        "Year 309: Eldarion sends a fleet to reinforce Eneldhor's "
        "presence in the east. At its head is Bregandil, son of his "
        "youngest sister Almarien. With Bregandil travels Cuilornir, "
        "his close friend. Carandur and Dor-Lonis are recovered. The "
        "alliance moves across the Lonis River. In the west, Eldarion "
        "crosses into Rhundaur. The inhabitants flock to his banner.\n\n"
        "Year 311: Bregandil founds the city of Eledhel. Colonists "
        "begin to trickle from Ardain and Eneldhor to the east.\n\n"
        "Year 313: Celebgaer falls to the alliance.\n\n"
        "Year 314: Eldarion grants Eledhel autonomy and has a crown "
        "crafted for his nephew. He travels to Eledhel and personally "
        "crowns Bregandil king. Cuilornir founds the Aegis Guard. "
        "Dyrithia, Dor-Edhel, and Gildaer fall to the alliance. "
        "Elonoch III flees Tirnost and re-establishes his power "
        "base in the Kharandish city of Khendrus.");

    addChapter("Bryleth the Vain",
        "Year 315: Elonoch III is murdered by his wife, Bryleth "
        "'the Vain'. She assumes the throne and sues for peace, "
        "relinquishing all lands west of Nernen and east of the "
        "Lonis River.\n\n"
        "[A marginal note in faded ink reads: 'There is much that "
        "the chronicles do not record about this woman. See the "
        "treatise On the Matter of Queen Bryleth for further "
        "discussion. The Scions have long suspected that more lies "
        "beneath the surface of this tale than history has "
        "recorded.']\n\n"
        "Year 326: Linwaeth founded.\n\n"
        "Year 327: Andurath declares war on Kharand.\n\n"
        "Year 398: Andurath and Kharand have peace. Kharand cedes "
        "Eslarach, Endurghul, and Khendazach to Andurath.");

    addChapter("The Battle of Utumnadh",
        "Year 406: A dark force, believed to be one of the fallen "
        "gods, sets up power within Utumnadh. The alliance "
        "formulates plans to attack.\n\n"
        "Year 409: The Battle of Utumnadh. The alliance is victorious, "
        "but at a great cost. Mirost, Hillgarath, and Eledhel are all "
        "bereft of their kings. Azgurdain II assumes the throne of "
        "Mirost, Aegdren son of Eldarendil that of Hillgarath, and "
        "Finwendil son of Bregandil that of Eledhel. The menace "
        "within Utumnadh grows silent.\n\n"
        "Year 443: Eldarion passes. Ellatan assumes the throne of "
        "Eneldhor.");
}
