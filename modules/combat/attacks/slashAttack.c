//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/combat/attacks/baseAttack.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        ::reset(arg);
        setDamageType("slash");
        addHitDictionary(({
            "slash", "swipe", "cut", "slice", "chop", "part", "shave", "slit",
            "flay", "lash", "gash", "hack", "score", "lacerate", "wound",
            "rip", "rend", "gouge", "thrash" }));

        // Simile entries don't really have to be similes - any text will do...
        addSimileDictionary(({
            "with a sickening wet sound", "as though ##TargetSubjective## were "
            "made of tofu", "in the ##BodyPart##", "deftly", "expertly" }));

        // Could also add a "damage dictionary" that returns messages based on
        // damage inflicted.

        // Messages have several key elements that can be replaced:
        // ##AttackerName## - Attacker's name
        // ##AttackerWeapon## - type of attacker's weapon (longsword, short sword,
        //   claymore...)
        // ##AttackerPossessive## - Attacker possessive / your
        // ##AttackerObjective## - Attacker's objective / you
        // ##AttackerSubjective## - Attacker's subjective/pronoun / you
        // ##Target[NWPOS]## - Target's (one of above 5)
        // ##HitDictionary## - random word from the hit dictionary (slash/slashes,
        //   chop/chops)
        // ##SimileDictionary## - random word from the simile dictionary
        // There's another special case for possessive:
        // ##[AT]P[::N]## - ##AP::N## -> "Bob's" or "your" for attacker named Bob
        //                  ##TP::N## -> "Bob's" or "your" for target named Bob
        addMissMessage("##AttackerName## clumsily ##HitDictionary## ##AttackerPossessive## "
            "##AttackerWeapon## at ##TargetName## but ##Infinitive::miss##.");

        // The second argument is the damage range over which this message can
        // occur.
        addHitMessage("##AttackerName## ##HitDictionary## ##AttackerPossessive## "
            "weapon into ##TargetName## ##SimileDictionary##.", "10-50");
        addHitMessage("##AttackerName## ##HitDictionary## ##AttackerPossessive## "
            "weapon into ##TargetName##. ##TargetSubjective## whines like a "
            "little girl.", "51-190");
    }
}
