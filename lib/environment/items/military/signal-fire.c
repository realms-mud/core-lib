//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseFire.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("signal fire");
    addAlias("beacon");
    addAlias("warning fire");
    suppressEntryMessage();

    addDescriptionTemplate(
        "a pile of wood and brush is arranged atop a stone platform, ready to "
        "be set alight as a signal. "
    );
    addActiveSourceOfLight(12,
        "a blazing signal fire roars atop the platform, its flames visible for "
        "miles"
    );

    addFireDescriptions(({
        "a pile of wood and brush is arranged atop a stone platform, ready to be set alight as a signal",
        "is a signal fire with faintly glowing embers among the unburned wood",
        "is a signal fire where occasional flickers of red flame dance among the kindling",
        "is a signal fire with small flames licking at the base of the pile",
        "is a signal fire where flames steadily consume the wood, crackling and sending up smoke",
        "is a signal fire where flames leap high, casting a bright glow",
        "is a signal fire with a strong blaze, sending sparks and smoke into the sky",
        "is a signal fire with a vigorous blaze, visible from a great distance",
        "a blazing signal fire roars atop the platform, its flames visible for miles"
    ));

    addItemTemplate(
        "The signal fire is built atop a stone platform, with wood and brush "
        "arranged for quick ignition. Soot stains the stones, and the air is "
        "tinged with the scent of smoke. ##UseDescriptionSet##"
    );
    }
