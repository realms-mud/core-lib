//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/dictionaries/attacks/baseAttack.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setDamageType("water");
    addHitDictionary(({
        "spray", "lash", "shoot", "splash", "drench" }));

    addSimileDictionary(({
        "with a ferocious deluge of water", "with a blast of icy water",
        "with a roaring wave of water" }));

    addMissMessage("##AttackerName## ##Infinitive::resemble## a wet dishcloth. "
        "How sad.");

    addHitMessage("##AttackerName## ##HitDictionary## ##TargetName## "
        "##SimileDictionary##.", "1-150");
}
