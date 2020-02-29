1. Return vector of objects
2. Ownership of this Vector among classes. (shared_ptr ?)
3. List Datastructure having vector of objects. Vector has limited capacity.
4. Search operation can be  asynchronous, i.e. get the record from db and meanwhile serve other requests from cache.
    . Implication
      - This is becoming a server/client model.
      - cache server serving the multiple client.
      - Very simple it is serving one client at a time, blocking it till the request is fulfilled and cache is updated from Db. 
        OR
        Complex Multithreaded Server/Clients enviornment, where Cache server serves the multiple client and meanwhile updating the
        cache from Db as well. DB itself uses multiple threads to search from database.

          client1(T1) --- getRecords(name, &vec){blocking call} -                             worker1(WT1)   .Cache.   .DB.   
                                                                    ====== serving queue === 
          client2(T2) --- getRecords(name, &vec){blocking call} -                             worker2(WT2)


        Flow:
        1. Client1 requests for a record.
        2. Server API puts it in the queue.
        3. Worker thread reads the request. There's one condition variable per WT which is used to signal the client when request is fulfilled.
        4. Worker thread reads from the cache, if record found returns the result to client.
        5. If record not found, Cache server ask DB to get the records. This request is again placed in queue CacheServer === DB.
        6. DB spawns multiple threads dividing file among threads to search for record.
          6.1 DB collates the records from threads and signals the CacheServer 
        7. Cache server updates the caches.
          7.1 Cache Server sends these records to cacheDB (a separate thread) which writes it to cacheDB file.
          7.2 Cache Server serves the client who was waiting for this.

5. Step by Step
  i) Implement multithreaded search.
  ii) Implement threaded search from CacheServer -- DB.
  iii) Implement threaded updated of records to CacheServer -- CacheDB.
  iv) Implement multiple clients.
