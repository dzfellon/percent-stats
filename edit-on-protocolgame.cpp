void ProtocolGame::AddPlayerStats(NetworkMessage &msg)
{
	msg.addByte(0xA0);

	msg.add<uint16_t>(std::min<int32_t>(player->getHealth() * 100.f / player->getMaxHealth(), std::numeric_limits<uint16_t>::max()));
	msg.add<uint16_t>(100);

	msg.add<uint32_t>(player->getFreeCapacity());

	msg.add<uint64_t>(player->getExperience());

	msg.add<uint16_t>(player->getLevel());
	msg.addByte(player->getLevelPercent());

	msg.add<uint16_t>(player->getBaseXpGain());		 // base xp gain rate
	msg.add<uint16_t>(player->getGrindingXpBoost()); // low level bonus
	msg.add<uint16_t>(player->getStoreXpBoost());	 // xp boost
	msg.add<uint16_t>(player->getStaminaXpBoost());	 // stamina multiplier (100 = 1.0x)

	msg.add<uint16_t>(std::min<int32_t>(player->getMana() * 100.f / player->getMaxMana(), std::numeric_limits<uint16_t>::max()));
	msg.add<uint16_t>(100);

	msg.addByte(player->getSoul());

	msg.add<uint16_t>(player->getStaminaMinutes());

	msg.add<uint16_t>(player->getBaseSpeed() / 2);

	Condition* condition = player->getCondition(CONDITION_REGENERATION);
	msg.add<uint16_t>(condition ? condition->getTicks() / 1000 : 0x00);

	msg.add<uint16_t>(player->getOfflineTrainingTime() / 60 / 1000);

	msg.add<uint16_t>(player->getExpBoostStamina()); // xp boost time (seconds)
	msg.addByte(1);									 // enables exp boost in the store

	msg.add<uint16_t>(player->getManaShield() * 100.f / player->getMaxManaShield());  // remaining mana shield
	msg.add<uint16_t>(100);  // total mana shield
}
