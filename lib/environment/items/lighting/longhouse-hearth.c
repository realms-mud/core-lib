//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseFire.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("longhouse hearth");
    addAlias("hearth");
    addAlias("central fire");
    addAlias("long fire");
    suppressEntryMessage();

    addDescriptionTemplate(
        "a long, open hearth runs down the center of the hall, filled with "
        "cold ashes and charred wood"
    );
    addActiveSourceOfLight(10,
        "a long, open hearth blazes in the center of the hall, its flames "
        "casting flickering light and sending smoke up toward the rafters"
    );

    addFireDescriptions(({
        "a long, open hearth runs down the center of the hall, filled with cold ashes and charred wood",
        "is a longhouse hearth with faintly glowing embers scattered among the ashes",
        "is a longhouse hearth where occasional flickers of red flame dance among the embers",
        "is a longhouse hearth with small flames licking at the remains of charred logs",
        "is a longhouse hearth where flames steadily consume partially-burned logs, crackling softly",
        "is a longhouse hearth where flames dance around seasoned logs, casting a warm, smoky glow",
        "is a longhouse hearth with a strong fire that sends smoke swirling up to the rafters",
        "is a longhouse hearth with a vigorous fire that pops and hisses as it burns",
        "a roaring fire blazes along the longhouse hearth, filling the hall with warmth and light"
        }));

    addItemTemplate(
        "The hearth is a long, shallow trench lined with stones, running the "
        "length of the hall. Soot stains the beams above, and the air is thick "
        "with the scent of woodsmoke. Benches and sleeping platforms line the "
        "walls nearby. ##UseDescriptionSet##"
    );
}
