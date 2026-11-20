//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("Tankard of Obstinance");
    addAlias("tankard");
    addAlias("ordinary-looking mug");
    addDescriptionTemplate("an ordinary-looking tankard");
    addItemTemplate("The plain metal tankard bears a few shallow runes "
        "cut into its base. It looks unremarkable until the light catches "
        "the worn letters.");
    addSomeLightDescriptionTemplate(
        "an ordinary-looking tankard rests on the rune-carved table");
    addDimLightDescriptionTemplate(
        "a small mug sits on the low table");
}
