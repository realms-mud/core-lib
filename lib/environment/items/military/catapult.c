//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("catapult");
    addAlias("siege engine");
    addAlias("stone thrower");

    addItemTemplate(
        "The catapult is a large siege engine, its wooden frame reinforced "
        "with iron. A massive arm is drawn back by ropes and a winch, ready "
        "to hurl stones at distant walls. "
    );

    addNearDarkDescriptionTemplate(
        "the outline of a catapult is barely visible, its bulk looming in the "
        "darkness"
    );
    addLowLightDescriptionTemplate(
        "a catapult stands in the gloom, its arm and frame just visible"
    );
    addDimLightDescriptionTemplate(
        "the catapult is faintly illuminated, its arm and winch apparent"
    );
    addSomeLightDescriptionTemplate(
        "the catapult is clearly visible, its ropes and arm ready for use"
    );
    addAdjectives(({ "large", "wooden", "siege", "wheeled", "counterweighted" }));
    addDescriptionTemplate("a ##Adjective## catapult with a heavy throwing arm");
}
