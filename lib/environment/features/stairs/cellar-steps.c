//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("cellar steps");
    suppressEntryMessage();
    addAlias("stairs");
    addAlias("steps");
    addAlias("cellar");

    addAdjectives(({ "that descend into cool darkness",
        "carved roughly from the living rock",
        "with moisture beading on the stone surface",
        "that disappear into underground shadows",
        "hewn with functional rather than aesthetic purpose",
        "showing the marks of pick and chisel",
        "that provide access to storage chambers",
        "with walls that weep moisture constantly" }));

    addDescriptionTemplate("cellar steps ##Adjective## "
        "provide access to the underground chambers");
    addSomeLightDescriptionTemplate("cellar steps ##Adjective## "
        "lead into the cool depths below");
    addNearDarkDescriptionTemplate("stone steps can be felt "
        "leading into deeper darkness");
    addLowLightDescriptionTemplate("rough cellar steps "
        "disappear into shadow below");
    addDimLightDescriptionTemplate("cellar steps ##Adjective## "
        "connect to the chambers beneath");

    addItemTemplate("The cellar steps are carved directly from bedrock "
        "with purely functional intent. Tool marks remain visible on the "
        "rough-hewn surfaces, while moisture constantly seeps through "
        "the stone, creating a perpetually damp environment. The passage "
        "leads to underground storage chambers where the cool, stable "
        "temperature preserves food and drink. Each step shows the weight "
        "of countless loads carried between the surface and depths.");
}
