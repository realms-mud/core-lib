//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/dictionaries/attacks/baseAttack.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setDamageType("physical");
    addHitDictionary(({
        "bash", "slam", "slap", "pummel", "crush", "pound", "punch", "smack",
        "assault" }));

    addSimileDictionary(({
        "smashing ##TargetPossessive## ##BodyPart## soundly", "repeatedly in "
        "the ##BodyPart##", "with a ##BodyPart##-shattering force" }));

    addMissMessage("##AttackerName## ##Infinitive::flail## wildly! Very theatric.");

    addHitMessage("##AttackerName## ##HitDictionary## ##TargetName## "
        "##SimileDictionary##.", "1-150");
}
