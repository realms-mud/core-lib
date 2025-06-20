//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("shaft of sunlight");
    addAlias("sunlight");
    addAlias("sunbeam");
    suppressEntryMessage();

    addItemTemplate(
        "A brilliant shaft of sunlight pierces the gloom, illuminating dust "
        "motes as it falls from above."
    );

    addNearDarkDescriptionTemplate(
        "a faint, golden glimmer hints at sunlight far above"
    );
    addLowLightDescriptionTemplate(
        "a pale shaft of sunlight filters down, barely illuminating the area"
    );
    addDimLightDescriptionTemplate(
        "a shaft of sunlight falls from above, casting a soft glow"
    );
    addSomeLightDescriptionTemplate(
        "a shaft of sunlight brightens the area, its warmth noticeable"
    );
    addDescriptionTemplate(
        "a brilliant shaft of sunlight streams down, flooding the area with "
        "golden light"
    );
    useExteriorLighting();
}
