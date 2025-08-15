//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/services/attacks/baseAttack.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setDamageType("physical");
    addHitDictionary(({
        "poke", "pierce", "impale", "puncture" }));

    addSimileDictionary(({
        "in ##TargetPossessive## ##BodyPart##", "repeatedly in "
        "the ##BodyPart##", "with a ##BodyPart##-splitting force" }));

    addMissMessage("##AttackerName## ##Infinitive::snap## ##AttackerPossessive##"
        " mandibles at the air.");

    addHitMessage("##AttackerName## ##HitDictionary## ##TargetName## "
        "##SimileDictionary## with ##AttackerPossessive## mandibles.",
        "1-150");
}
