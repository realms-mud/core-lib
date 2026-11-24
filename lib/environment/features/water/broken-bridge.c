//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("broken bridge");
    addAlias("bridge");
    addAlias("span");
    addDescriptionTemplate("a broken timber bridge over a fast stream");
    addNearDarkDescriptionTemplate("a gap where the bridge should be");
    addLowLightDescriptionTemplate(
        "a broken bridge with its far end hanging over the water");
    addDimLightDescriptionTemplate(
        "a collapsed timber span above a rocky stream");
    addSomeLightDescriptionTemplate(
        "a broken bridge whose middle section has fallen into the stream");
    addItemTemplate("The near half of the bridge still rests on its "
        "stone abutment. Beyond it, the deck has sheared away; "
        "splintered beams turn in the current below. The far bank "
        "is close enough to tempt a jump and far enough to punish one. "
        "A line of pale stones marks the safer ford downstream.");
}
