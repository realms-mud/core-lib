//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("ore cart");
    addAlias("mine cart");
    addAlias("rail cart");
    addAlias("tub");

    addAdjectives(({ "iron", "battered", "rust-streaked", "heavy",
        "dented", "ore-laden", "small", "wheeled", "old", "sturdy" }));

    addDescriptionTemplate("a ##Adjective## ore cart sitting on iron rails");

    addItemTemplate(
        "The ore cart is a small iron tub on flanged wheels, designed to "
        "run along wooden rails laid in the mine tunnels. Its sides are "
        "dented and rust-streaked, and chunks of raw ore and stone dust "
        "fill the bottom. The wheels squeal on their axles."
    );

    addSomeLightDescriptionTemplate(
        "an ore cart sits on its rails, chunks of rock visible in its bed"
    );
    addDimLightDescriptionTemplate(
        "a small iron cart sits on rails, dark with ore dust"
    );
    addLowLightDescriptionTemplate(
        "a small wheeled container sits on rails"
    );
    addNearDarkDescriptionTemplate(
        "the smell of raw stone and metal dust suggests mine workings nearby"
    );
}
