//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/dictionaries/attacks/baseAttack.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setDamageType("acid");
    addHitDictionary(({
        "corrode", "dissolve", "erode", "etch", "burn", "melt", "liquify" }));

    addSimileDictionary(({
        "through ##TargetPossessive## ##BodyPart##", "causing a sickening sizzle",
        "and a nasty stench wafts from the vicinity of ##TargetName##" }));

    addMissMessage("##AttackerName## ##Infinitive::spray## acid everywhere "
        "except ##TargetName##.");

    addHitMessage("##AttackerName## ##HitDictionary## ##TargetName## "
        "with acid ##SimileDictionary##.", "default");
    addHitMessage("##AttackerName## ##Infinitive::splash## ##TargetName## right "
        "in the ##BodyPart## with a jet of acid.",
        "51-150");
}
