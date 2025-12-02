//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/services/attacks/baseAttack.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setDamageType("paralysis");
    addHitDictionary(({
        "stun", "immobilize", "stupefy", "daze", "startle", "befuddle",
        "shock" }));

    addSimileDictionary(({
        "with a mind-bending force", "with a brain-scrambling force",
        "with a dumbfounding force" }));

    addMissMessage("##AttackerName## ##Infinitive::drool##, momentarily "
        "stupefied.");

    addHitMessage("##AttackerName## ##HitDictionary## ##TargetName## "
        "##SimileDictionary##.", "1-150");
}
