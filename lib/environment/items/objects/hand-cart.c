//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("hand cart");
    addAlias("cart");
    addAlias("pushcart");
    addAlias("barrow");

    addAdjectives(({ "wooden", "sturdy", "battered", "creaking", "small",
        "well-used", "weathered", "rustic", "iron-wheeled", "rickety" }));

    addDescriptionTemplate("a ##Adjective## hand cart for hauling goods");

    addItemTemplate(
        "This two-wheeled cart is built for pushing by hand, its bed of "
        "rough-sawn planks stained by years of hauling everything from "
        "turnips to timber. The iron-rimmed wheels are pitted with rust, "
        "and the handles are worn smooth by countless grips."
    );

    addSomeLightDescriptionTemplate(
        "a hand cart sits nearby, its wooden bed empty and waiting"
    );
    addDimLightDescriptionTemplate(
        "a hand cart is visible, its wheels and handles outlined in the gloom"
    );
    addLowLightDescriptionTemplate(
        "a low shape with wheels suggests an abandoned cart"
    );
    addNearDarkDescriptionTemplate(
        "something with wheels is parked nearby, barely visible"
    );
}
