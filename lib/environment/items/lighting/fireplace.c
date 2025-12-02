//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseFire.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("fireplace");
    addAlias("fire");
    addAlias("hearth");
    suppressEntryMessage();

    addDescriptionTemplate("a large, stone fireplace lies dormant with cold "
        "ashes in its hearth");
    addActiveSourceOfLight(8, "a roaring fire burns brightly in the large stone "
        "fireplace, casting warm light");

    addFireDescriptions(({
        "a large, stone fireplace lies dormant with cold ashes in its hearth",
        "is a stone fireplace with faintly glowing embers among the ashes",
        "is a stone fireplace where occasional flickers of red flame dance among "
            "the embers",
        "is a stone fireplace with small flames licking at the remains of "
            "charred logs",
        "is a stone fireplace where flames steadily consume partially-burned logs, "
            "crackling softly",
        "is a stone fireplace where flames dance merrily around seasoned logs, "
            "casting a warm glow",
        "is a stone fireplace with a strong fire that sends sparks up the chimney "
            "as it burns",
        "is a large stone fireplace with a vigorous fire that pops and hisses as "
            "it burns",
        "a roaring fire burns brightly in the large stone fireplace, filling "
            "the area with warmth"
        }));

    addItemTemplate("the fireplace is built of massive stone blocks, blackened by "
        "years of use. Its mantel bears weathered carvings. Iron tools for "
        "tending the fire rest nearby. ##UseDescriptionSet##");
}
