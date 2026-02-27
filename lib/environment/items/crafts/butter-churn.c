//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("butter churn");
    addAlias("churn");
    addAlias("dasher churn");

    addAdjectives(({ "wooden", "tall", "narrow", "well-used", "old",
        "sturdy", "cream-stained", "simple", "functional", "upright" }));

    addDescriptionTemplate("a ##Adjective## butter churn standing by the wall");

    addItemTemplate(
        "The butter churn is a tall, narrow wooden barrel with a plunger "
        "handle protruding from its lidded top. The interior is stained "
        "white with cream residue, and the dasher — a wooden cross on a "
        "long pole — shows the wear of countless hours of rhythmic "
        "churning. A faint smell of buttermilk clings to the wood."
    );

    addSomeLightDescriptionTemplate(
        "a butter churn stands by the wall, its plunger handle upright"
    );
    addDimLightDescriptionTemplate(
        "a tall narrow barrel with a handle is visible by the wall"
    );
    addLowLightDescriptionTemplate(
        "a tall narrow shape stands against the wall"
    );
    addNearDarkDescriptionTemplate(
        "the faint scent of buttermilk suggests a churn nearby"
    );
}
