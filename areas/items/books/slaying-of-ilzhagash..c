//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/book.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "The Slaying of Ilzhagash");
    set("short", "A dwarven account of dragon-slaying");
    set("title",
        "The Slaying of Ilzhagash: As Recorded by the Dwarves of "
        "Khazurath and the League");
    set("aliases",
        ({ "ilzhagash saga", "dwarven dragon account", "league record",
            "book", "account" }));
    set("long",
        "A formal account set down by the dwarves concerning the coming "
        "of the dragon Ilzhagash and its destruction. The tone is measured, "
        "proud, and precise, honoring those who stood and did not yield.");

    addChapter("Of the Coming of Ilzhagash",
        "In the year 1692, the wyrm Ilzhagash came forth from Utumnadh.\n"
        "It descended upon Arnost in fire and ruin.\n"
        "Walls were broken, and the upper halls laid waste.\n"
        "Men fled before it, as was their nature.\n"
        "Word was sent with haste to the League of Dwarven Nations.\n"
        "The summons was answered without delay or dispute.\n"
        "For dragons are the ancient foes of our kind.\n"
        "And no dwarf who hears such a call remains seated.\n");

    addChapter("Of the Muster of the League",
        "Hosts were gathered from Ekalbor, Aglarond, and Khazurath.\n"
        "Dhuran XI Stonehelm sent warriors of proven lineage.\n"
        "Glanrin IV sent smiths whose craft was equal to their arms.\n"
        "Khazurin brought forth veterans of deep roads and old wars.\n"
        "Axes were honed, mail was set, and oaths were spoken.\n"
        "Each warrior named his line, that none be forgotten.\n"
        "They marched not in haste, but in certainty.\n"
        "For the end of the dragon was already resolved in their hearts.\n");

    addChapter("Of the First Meeting",
        "Ilzhagash met them before the broken gates of Mirost.\n"
        "Its fire ran like molten stone across shield and wall.\n"
        "Many were scorched, and some were lost in that first breath.\n"
        "Yet the line held, as it must, and as it was sworn to do.\n"
        "No dwarf turned from the flame.\n"
        "No dwarf cast aside shield or axe.\n"
        "The beast circled, seeking weakness, and found none given.\n"
        "Thus was the battle joined in earnest.\n");

    addChapter("Of the Breaking of the Wyrm",
        "They advanced beneath the smoke, step by measured step.\n"
        "Shields were locked; axes rose and fell in steady rhythm.\n"
        "The dragon struck, and was struck in turn.\n"
        "Its scales were hard, yet not beyond the making of dwarves.\n"
        "Glanrin's smiths had wrought edges fit for such a foe.\n"
        "Khazurin's veterans held the flanks against claw and tail.\n"
        "Dhuran's line pressed forward toward the beast's heart.\n"
        "At last, the wyrm faltered, its fire broken, its strength failing.\n");

    addChapter("Of the Final Blow",
        "It is recorded that the killing stroke was struck in unity.\n"
        "Many axes found their mark in the same moment.\n"
        "The beast fell, and the ground trembled beneath its weight.\n"
        "Its death cry was heard in the deep places of the world.\n"
        "Thus ended Ilzhagash, foe of dwarves and burner of halls.\n"
        "Let no single name claim the deed above the others.\n"
        "For the victory belonged to the League entire.\n"
        "And so it is written, and so it is remembered.\n");

    addChapter("Of the Cost and the Oath Renewed",
        "Many fell in that battle, and their names are set in stone.\n"
        "Their lineages are recorded, their deeds accounted.\n"
        "No loss is forgotten among our people.\n"
        "The halls were filled with mourning, yet also with pride.\n"
        "For the ancient oath was upheld without fail.\n"
        "Let dragons come forth from shadow or mountain.\n"
        "Let fire fall upon stone and steel.\n"
        "The dwarves will answer, as they have always answered.\n");
}
