inherit "/lib/modules/combat/attacks/baseAttack.c";

public void init()
{
    ::init();
    setDamageType("thrust");
    addHitDictionary(({
        "impale", "pierce", "puncture", "skewer", "gore", "gouge",
        "perforate" }));

    addSimileDictionary(({
        "expertly", "fiercely", "through ##TargetPossessive::Name## ##BodyPart##",
        "viciously" }));

    addMissMessage("##AttackerName## ##Infinitive::thrust## impressively at"
        " nothing whatsoever!");

    addHitMessage("##AttackerName## ##HitDictionary## ##TargetName## "
        "##SimileDictionary## with ##AttackerPossessive##"
        " ##AttackerWeapon##.", "1-50");
}



