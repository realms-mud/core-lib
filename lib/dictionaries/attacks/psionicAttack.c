//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/dictionaries/attacks/baseAttack.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setDamageType("psionic");
    addHitDictionary(({
        "blast", "slam", "menace", "blast", "crush" }));

    addSimileDictionary(({
        "with a blast of psionic energy", "with a wave of mental force",
        "with ripples of mental energy" }));

    addMissMessage("##AttackerName## ##Infinitive::stare## deeply at "
        "##TargetName##. Everyone is impressed.");

    addHitMessage("##AttackerName## ##HitDictionary## ##TargetName##"
        " ##SimileDictionary##.", "1-150");
}
