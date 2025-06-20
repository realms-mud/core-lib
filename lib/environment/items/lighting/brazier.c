//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseFire.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("brazier");
    addAlias("coal brazier");
    addAlias("iron brazier");
    suppressEntryMessage();

    addDescriptionTemplate("a sturdy iron brazier stands on three legs, filled "
        "with cold ashes and bits of charcoal");
    addActiveSourceOfLight(7, "a glowing brazier radiates warmth and light, "
        "its coals burning with a steady red glow");

    addFireDescriptions(({
        "a sturdy iron brazier stands on three legs, filled with cold ashes and bits of charcoal",
        "is a brazier with faintly glowing coals among the ashes",
        "is a brazier where occasional flickers of red flame dance among the coals",
        "is a brazier with small flames licking at the remains of charred wood",
        "is a brazier where flames steadily consume partially-burned fuel, crackling softly",
        "is a brazier where flames dance around the coals, casting a warm glow",
        "is a brazier with a strong fire that sends sparks into the air as it burns",
        "is a large brazier with a vigorous fire that pops and hisses as it burns",
        "a roaring fire burns brightly in the brazier, filling the area with warmth"
        }));

    addItemTemplate("the brazier is made of blackened iron, its bowl supported "
        "by three sturdy legs. Tongs and a poker rest nearby. ##UseDescriptionSet##");
}
