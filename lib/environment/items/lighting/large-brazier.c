//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseFire.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("large brazier");
    addAlias("brazier");
    addAlias("iron brazier");
    suppressEntryMessage();

    addDescriptionTemplate(
        "a large iron brazier stands on sturdy legs, filled with cold ashes and "
        "bits of charcoal"
    );
    addActiveSourceOfLight(9,
        "a large brazier glows with a strong, steady fire, radiating heat and "
        "light"
    );

    addFireDescriptions(({
        "a large iron brazier stands on sturdy legs, filled with cold ashes and bits of charcoal",
        "is a brazier with faintly glowing coals among the ashes",
        "is a brazier where occasional flickers of red flame dance among the coals",
        "is a brazier with small flames licking at the remains of charred wood",
        "is a brazier where flames steadily consume partially-burned fuel, crackling softly",
        "is a brazier where flames dance around the coals, casting a warm glow",
        "is a brazier with a strong fire that sends sparks into the air as it burns",
        "is a large brazier with a vigorous fire that pops and hisses as it burns",
        "a roaring fire burns brightly in the large brazier, filling the area with warmth"
        }));

    addItemTemplate(
        "The brazier is made of blackened iron, its bowl supported by three "
        "sturdy legs. Tongs and a poker rest nearby. ##UseDescriptionSet##"
    );
}
