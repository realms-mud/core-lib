//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("shaft of moonlight");
    addAlias("moonlight");
    addAlias("moonbeam");
    suppressEntryMessage();

    addItemTemplate(
        "A pale shaft of moonlight falls from above, lending the area a "
        "silvery, ethereal glow."
    );

    addNearDarkDescriptionTemplate(
        "a faint, silvery glimmer hints at moonlight far above"
    );
    addLowLightDescriptionTemplate(
        "a dim shaft of moonlight filters down, barely illuminating the area"
    );
    addDimLightDescriptionTemplate(
        "a shaft of moonlight falls from above, casting a cool, gentle glow"
    );
    addSomeLightDescriptionTemplate(
        "a shaft of moonlight brightens the area with a soft, silvery light"
    );
    addDescriptionTemplate(
        "a brilliant shaft of moonlight streams down, bathing the area in "
        "ethereal silver"
    );
    useExteriorLighting();
}
