//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseFire.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("beacon");
    addAlias("signal beacon");
    addAlias("warning beacon");
    suppressEntryMessage();

    addDescriptionTemplate(
        "a pile of wood and brush is arranged atop a stone platform, ready to "
        "be set alight as a beacon"
    );
    addActiveSourceOfLight(14,
        "a blazing beacon roars atop the platform, its flames visible for miles"
    );

    addFireDescriptions(({
        "a pile of wood and brush is arranged atop a stone platform, ready to be set alight as a beacon",
        "is a beacon with faintly glowing embers among the unburned wood",
        "is a beacon where occasional flickers of red flame dance among the kindling",
        "is a beacon with small flames licking at the base of the pile",
        "is a beacon where flames steadily consume the wood, crackling and sending up smoke",
        "is a beacon where flames leap high, casting a bright glow",
        "is a beacon with a strong blaze, sending sparks and smoke into the sky",
        "is a beacon with a vigorous blaze, visible from a great distance",
        "a blazing beacon roars atop the platform, its flames visible for miles"
    ));

    addItemTemplate(
        "The beacon is built atop a stone platform, with wood and brush "
        "arranged for quick ignition. Soot stains the stones, and the air is "
        "tinged with the scent of smoke. ##UseDescriptionSet##"
    );
    }
