//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseFire.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("hearth");
    addAlias("open hearth");
    addAlias("stone hearth");
    suppressEntryMessage();

    addDescriptionTemplate(
        "a wide, open hearth sits at the center of the room, filled with cold "
        "ashes and charred wood"
    );
    addActiveSourceOfLight(8,
        "a wide, open hearth blazes with fire, casting warmth and flickering "
        "light throughout the room"
    );

    addFireDescriptions(({
        "a wide, open hearth sits at the center of the room, filled with cold ashes and charred wood",
        "is a hearth with faintly glowing embers scattered among the ashes",
        "is a hearth where occasional flickers of red flame dance among the embers",
        "is a hearth with small flames licking at the remains of charred logs",
        "is a hearth where flames steadily consume partially-burned logs, crackling softly",
        "is a hearth where flames dance around seasoned logs, casting a warm glow",
        "is a hearth with a strong fire that sends smoke swirling up to the rafters",
        "is a hearth with a vigorous fire that pops and hisses as it burns",
        "a roaring fire blazes in the hearth, filling the room with warmth and light"
        }));

    addItemTemplate(
        "The hearth is a broad, stone-lined pit, open to the room and used for "
        "both warmth and cooking. Soot stains the stones, and iron tools rest "
        "nearby. ##UseDescriptionSet##"
    );
}
