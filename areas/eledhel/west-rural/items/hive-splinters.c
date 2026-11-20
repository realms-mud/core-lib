//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("hive splinters");
    addAlias("broken hive fragments");
    addAlias("broken skep");
    addDescriptionTemplate("splintered pieces of a straw hive");
    addItemTemplate(
        "A broken section of straw skep lies beside the stand. The weave "
        "is crushed inward, with several deep gouges through the binding. "
        "Beeswax has been smeared toward the ravine, but there are no "
        "cart ruts or cut straps.");
    addNearDarkDescriptionTemplate("a broken, tangled shape in the grass");
    addLowLightDescriptionTemplate("splintered straw beside a low stand");
    addDimLightDescriptionTemplate(
        "a crushed hive section with long gouges in its binding");
    addSomeLightDescriptionTemplate(
        "a broken hive section marked by deep gouges");
}
