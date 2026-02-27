//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("chain links");
    addAlias("chainmail links");
    addAlias("mail rings");
    addAlias("loose rings");

    addAdjectives(({ "iron", "tiny", "scattered", "shining", "unfinished",
        "piled", "open", "riveted", "loose", "countless" }));

    addDescriptionTemplate("##Adjective## chain links piled in a bowl on the bench");

    addItemTemplate(
        "A shallow wooden bowl on the workbench holds hundreds of tiny "
        "iron rings, each one individually cut from drawn wire. Some are "
        "open, waiting to be woven into mail and riveted shut; others are "
        "already closed. The work of assembling a full hauberk from these "
        "individual links is clearly a task of staggering patience."
    );

    addSomeLightDescriptionTemplate(
        "a bowl of tiny iron chain links glints on the workbench"
    );
    addDimLightDescriptionTemplate(
        "a bowl of small metallic objects glints faintly on the bench"
    );
    addLowLightDescriptionTemplate(
        "something metallic fills a bowl on the workbench"
    );
    addNearDarkDescriptionTemplate(
        "a faint metallic glint and the clink of small rings come from "
        "the bench"
    );
}
