//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("wizard tower steps");
    suppressEntryMessage();
    addAlias("stairs");
    addAlias("steps");
    addAlias("wizard");
    addAlias("tower");
    addAlias("magical");
    addAlias("enchanted");

    addAdjectives(({ "that levitate slightly above their stone foundations",
        "carved from meteoric stone that pulses with starlight",
        "that rearrange themselves when no one is watching",
        "inscribed with runes that burn with cold fire",
        "made from crystallized time itself",
        "that whisper incantations in forgotten tongues",
        "forged from the bones of ancient dragons",
        "that exist in seventeen dimensions simultaneously" }));

    addDescriptionTemplate("wizard tower steps ##Adjective## "
        "defy the laws of mundane architecture");
    addSomeLightDescriptionTemplate("wizard tower steps ##Adjective## "
        "blaze with arcane power");
    addNearDarkDescriptionTemplate("steps of pure magical energy "
        "throb with eldritch power in the darkness");
    addLowLightDescriptionTemplate("enchanted tower steps "
        "illuminate themselves with writhing magical flames");
    addDimLightDescriptionTemplate("wizard tower steps ##Adjective## "
        "bend reality around their supernatural presence");
    addSourceOfLight(5);

    addItemTemplate("The wizard tower steps are marvels of magical "
        "engineering that mock the very concept of ordinary construction. "
        "Each step hovers a finger's width above its base, supported by "
        "invisible forces that make the air itself hum with power. Runes "
        "of binding and levitation spiral around their edges, occasionally "
        "erupting in cascades of silver sparks. The stone - if it can be "
        "called stone - shifts between translucent crystal and solid "
        "obsidian depending on the viewer's magical sensitivity. Walking "
        "upon them requires no effort, as if the steps themselves carry "
        "you upward through sheer force of will.");
}
