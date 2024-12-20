//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/dictionaries/attacks/baseAttack.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setDamageType("bludgeon");
    addHitDictionary(({
        "bash", "smash", "pummel", "slam", "smack", "clobber",
        "whack" }));

    addSimileDictionary(({
        "soundly", "solidly", "on ##TargetPossessive## ##BodyPart##",
        "viciously", "with bone-crushing force" }));

    addMissMessage("##AttackerName## ##Infinitive::bludgeon## invisible foes!");

    addHitMessage("##AttackerName## ##HitDictionary## ##TargetName## "
        "##SimileDictionary##.", "1-150");
}
