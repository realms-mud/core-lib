//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/dictionaries/attacks/baseAttack.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setDamageType("earth");
    addHitDictionary(({
        "blast", "crush", "pummel", "concuss", "flatten", "beat", "slam",
        "bash", "smash", "pound", "cudgel" }));

    addSimileDictionary(({
        "upside ##TargetPossessive## ##BodyPart##", "with an earth-shaking "
        "rumble", "with a head-splitting roar" }));

    addMissMessage("##AttackerName## ##Infinitive::gesticulate## wildly but "
        "##Infinitive::produce## little more than street theater.");

    addHitMessage("##AttackerName## ##Infinitive::summon## the powers of earth"
        " and ##HitDictionary## ##TargetName## ##SimileDictionary##.", "1-150");
}
