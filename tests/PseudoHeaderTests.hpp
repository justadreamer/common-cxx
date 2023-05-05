/* *********************************************************************
 * This Original Work is copyright of 51 Degrees Mobile Experts Limited.
 * Copyright 2022 51 Degrees Mobile Experts Limited, Davidson House,
 * Forbury Square, Reading, Berkshire, United Kingdom RG1 3EU.
 *
 * This Original Work is licensed under the European Union Public Licence
 * (EUPL) v.1.2 and is subject to its terms as set out below.
 *
 * If a copy of the EUPL was not distributed with this file, You can obtain
 * one at https://opensource.org/licenses/EUPL-1.2.
 *
 * The 'Compatible Licences' set out in the Appendix to the EUPL (as may be
 * amended by the European Commission) shall be deemed incompatible for
 * the purposes of the Work and the provisions of the compatibility
 * clause in Article 5 of the EUPL shall not apply.
 *
 * If using the Work as, or as part of, a network application, by
 * including the attribution notice(s) required under Article 5 of the EUPL
 * in the end user terms of the application under an appropriate heading,
 * such notice(s) shall fulfill the requirements of that article.
 * ********************************************************************* */

#include "Base.hpp"
#include "../headers.h"
#include "../evidence.h"
#include "StringCollection.hpp"

typedef struct test_key_value_pair_t {
	char key[50];
	char value[50];
} testKeyValuePair;

typedef struct test_expected_result_t {
	char result[50];
	fiftyoneDegreesEvidencePrefix prefix;
} testExpectedResult;

class PseudoHeaderTests : public Base {
public:
	void SetUp();
	void TearDown();
	void createHeaders(
		const char** headersList,
		int headersCount,
		bool expectUpperPrefixedHeaders);
	void addEvidence(
		testKeyValuePair* evidenceList,
		int size,
		fiftyoneDegreesEvidencePrefix prefix);
	void checkResults(const testExpectedResult *expectedEvidence, int size);
	void removePseudoEvidence(size_t bufferSize);
	int getNextPseudoIndex(const char* headers[], int size, int index);
protected:
	StringCollection* strings = NULL;
	fiftyoneDegreesHeaders* acceptedHeaders = NULL;
	fiftyoneDegreesEvidenceKeyValuePairArray* evidence = NULL;
};