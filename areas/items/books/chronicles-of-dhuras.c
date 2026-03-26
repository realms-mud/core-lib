//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/book.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Chronicles of Dhuras and the Dragon Years");
    set("short", "A scholarly account of alliances and ruin");
    set("title",
        "Chronicles of Dhuras and the Dragon Years: From the League "
        "of Dwarves to the Fall of Mirost");
    set("aliases",
        ({ "dhuras chronicle", "dragon years", "league of dwarves",
            "chronicle", "book", "account" }));
    set("long",
        "A measured account compiled from royal archives, dwarven "
        "records, and the writings of the Dhurasian order. It traces "
        "the founding of alliances, the rise of Argloth, and the "
        "devastation wrought by dragons from Utumnadh.");

    addChapter("On the League of Dwarven Nations",
        "In the year 1204 was founded the League of Dwarven Nations.\n"
        "Emissaries gathered in Mirost under solemn oath and witness.\n"
        "Dhuran XI Stonehelm of Ekalbor sent word and gold.\n"
        "Glanrin IV of Aglarond brought craft and counsel.\n"
        "Khazurin of Khazurath spoke for the deep halls.\n"
        "Azgurin IX received them in Mirost with measured honor.\n"
        "Their accord bound trade, war, and mutual defense.\n"
        "It is said no oath of stone had been so binding in an age.\n"
        "From this council arose a unity long absent among the dwarves.\n"
        "Its strength would soon be tested beyond all expectation.\n");

    addChapter("On Argloth and the Tower of Dhuras",
        "In 1218, Argloth the Wise came into the keeping of Dhuras.\n"
        "King Balgamir granted him the tower and its authority.\n"
        "He was named Governor, though many called him master.\n"
        "His learning was deep, and his command of craft greater still.\n"
        "Students gathered, and an order took form around him.\n"
        "They studied not only war, but the hidden workings of the world.\n"
        "Dhuras grew from fortress into seat of knowledge.\n"
        "Few foresaw the reach of Argloth’s later ambition.\n"
        "[A marginal note: 'He was great before he was feared.']\n");

    addChapter("On the Fading of Balgamir",
        "In 1219, King Balgamir fell to a wasting illness unnamed.\n"
        "No healer could account for its cause or its progress.\n"
        "The Werric Knighthood suffered grievous loss in this time.\n"
        "Many among the aristocracy followed the king into death.\n"
        "Whether plague, poison, or darker cause remains disputed.\n"
        "Nienwen was raised to the throne of Hillgarath.\n"
        "Her rule began in uncertainty, yet did not falter.\n"
        "Records of this year are fragmentary and often contradictory.\n"
        "Some later scholars suspect design where none was proven.\n");

    addChapter("On the Passing of Crowns",
        "In 1295, Aramed took the throne of Eledhel.\n"
        "Years later, Nienwen relinquished rule to her son Eneldin.\n"
        "This was in 1356, when he had come into full strength.\n"
        "Her abdication is recorded as voluntary and without strife.\n"
        "The transition was marked by stability, rare in that age.\n"
        "Eledhel and Hillgarath both prospered for a time.\n"
        "Yet such periods of calm seldom endure unchallenged.\n");

    addChapter("On the Wars of Andurath",
        "In 1412, Andurath moved openly against the alliance.\n"
        "The Battle of Helcarion proved decisive and costly.\n"
        "Eneldin was slain, and his line passed to Eneldin II.\n"
        "War continued in cycles, neither side yielding fully.\n"
        "In 1438, Aranadur took the throne of Eledhel.\n"
        "In 1491, Eneldin II fell also in battle.\n"
        "Palandil then assumed rule in Hillgarath.\n"
        "These years are marked by attrition and shifting borders.\n");

    addChapter("On Orcs and the Shadowed Years",
        "Argaldin rose in Eledhel in 1578 and ruled in strength.\n"
        "Palandil II followed in Hillgarath in 1608.\n"
        "Yet in 1668, Argaldin fell in battle against orcs.\n"
        "Ardanel succeeded him amid renewed instability.\n"
        "Raids increased in frequency and coordination.\n"
        "Some accounts speak of guidance beyond mere tribal war.\n"
        "These whispers would later gain grim substance.\n");

    addChapter("On the Keepers of the Night",
        "In 1689, the Keepers of the Night first appear in record.\n"
        "Their origin is unknown; their purpose less so.\n"
        "They spread corruption, and gathered in hidden places.\n"
        "Reports speak of rites and devotion to a dark power.\n"
        "In 1691, Argloth marched against them without delay.\n"
        "He broke their stronghold and claimed Zhardeg.\n"
        "Whether this was victory or transformation is debated.\n"
        "[A marginal note: 'He fought darkness, and kept it.']\n");

    addChapter("On the Dragons of Utumnadh",
        "In 1692, the dragon Ilzhagash descended upon Mirost.\n"
        "The dwarves met it in battle and slew the beast.\n"
        "Their losses were great, though victory was certain.\n"
        "Yet before the year’s end, another came: Sylthasis.\n"
        "It issued from Utumnadh, greater in fury than the first.\n"
        "In 1693, Arnost was destroyed utterly by its fire.\n"
        "Mirost too fell, its defenses broken beyond repair.\n"
        "Survivors fled, many seeking refuge in Hillgarath.\n"
        "Others were taken in by Khazurath beneath the earth.\n");

    addChapter("On Renewal After Ruin",
        "In 1698, Arandahir took the throne of Eledhel.\n"
        "In 1704, the city of Eldarel was founded anew.\n"
        "These acts marked the will to endure beyond devastation.\n"
        "In 1714, Emandil assumed rule in Hillgarath.\n"
        "The lands remained scarred, yet not broken.\n"
        "From ruin arose new strength, though memory lingered.\n"
        "The shadow of Utumnadh had not wholly passed.\n");
}
