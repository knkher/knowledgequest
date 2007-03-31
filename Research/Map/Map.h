#pragma once

namespace Utilities{

	namespace Map{

		

		class SafeData{
		public:
			void * m_pData;
			unsigned long m_ulSize;
			void clean();
			
		public:			
			SafeData();
			SafeData(SafeData &val);
			~SafeData();

			//Deep Copies
			bool deepCopy(SafeData * pSource);
			bool deepCopy(void * pData, unsigned long ulDataSize);
			void operator = (SafeData & sdSource);


			bool operator == (SafeData & sdSource);
			bool isEqual(void * pData, unsigned long ulDataSize);

		};

		class Value : public SafeData{

		};

		class Key : public SafeData{

		};

		namespace HashFunctions{
			class IHashFunction{
			public:
				virtual unsigned long GetRange() = 0;
				virtual unsigned long Hash(void * pData, unsigned long ulDataSize) = 0;
			};

			class ModHash:public IHashFunction{
			private:
				unsigned long m_ulRange;
			public:
				ModHash(unsigned long ulRange = 256);
				virtual unsigned long GetRange();
				virtual unsigned long Hash(void * pData, unsigned long ulDataSize);

			};
		};



		class IMapEntry{
		public:
			Key k;
			Value v;
			IMapEntry * pNext;
		};

		class IMap{
		public:
			virtual bool lookup(void * pKey, unsigned long ulKeySize, Value & v) = 0;
			virtual void setAt(void * pKey, unsigned long ulKeySize, void * pValue, unsigned long ulValueSize) = 0;
			virtual ~IMap(){}
		};


		class LinearMap: public IMap{
		private:
			IMapEntry * m_pEntries;
			unsigned long m_ulEntriesCount;

			IMapEntry * findValue(void * pKey, unsigned long ulKeySize);
						
		public:
			LinearMap();
			~LinearMap(void);


			
			virtual bool lookup(void * pKey, unsigned long ulKeySize, Value & v);
			virtual void setAt(void * pKey, unsigned long ulKeySize, void * pValue, unsigned long ulValueSize);


		};

		class SimpleBucketMap : public IMap
		{

		private:

			unsigned long m_ulBuckets;
			LinearMap ** m_pBuckets;

			HashFunctions::IHashFunction * m_pHasher;
			unsigned long m_ulRange;
						
		public:
			SimpleBucketMap(HashFunctions::IHashFunction * pHasher);
			~SimpleBucketMap(void);


			virtual bool lookup(void * pKey, unsigned long ulKeySize, Value & v);
			virtual void setAt(void * pKey, unsigned long ulKeySize, void * pValue, unsigned long ulValueSize);


		};
	};
};
