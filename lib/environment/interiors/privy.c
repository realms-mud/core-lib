//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/interiors/baseInterior.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("privy");

    addAdjectives(({
        "small stone chamber with a wooden seat positioned over a vertical shaft",
        "cramped privy tucked into an outer wall, where a draft rises from below",
        "humble garderobe built into a castle wall with a long drop to the moat",
        "private alcove with a wooden bench and a hole leading to a cesspit",
        "narrow chamber where the smell confirms its function despite attempts "
            "at cleanliness",
        "modest privy where dried herbs and rushes attempt to mask unpleasant odors",
        "secluded stone closet with a surprisingly comfortable wooden seat",
        "simple waste chamber where ventilation comes from an angled shaft",
        "tiny room built as an afterthought into the thickness of a tower wall",
        "drafty privy where cleverly designed channels divert waste away",
        "functional chamber with a hinged wooden seat and strategically placed "
            "window",
        "small convenience built to overhang a castle wall for natural disposal",
        "makeshift privy where lime powder in a bucket stands ready for use",
        "surprising chamber with actual privacy, a rarity in medieval facilities",
        "rustic facility where a reed basket holds clean moss and soft leaves"
        }));

    addDescriptionTemplate("a ##Adjective##");

    addNearDarkDescriptionTemplate(
        "a pitch-black privy chamber where you must feel your way to the wooden "
        "seat, hoping not to miss your target"
    );

    addLowLightDescriptionTemplate(
        "a dimly lit privy, where shapes are barely visible but the function of "
        "the chamber is unmistakable from the draft and smell"
    );

    addDimLightDescriptionTemplate(
        "a dimly-lit ##Adjective##, the feeble light from a narrow window or "
        "arrow slit providing just enough illumination for necessary business"
    );

    addSomeLightDescriptionTemplate(
        "a well-lit ##Adjective##, a surprising amount of sunlight entering "
        "through ventilation shafts or windows to make the space almost pleasant"
    );
}
