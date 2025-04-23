declare module 'libvictor.node' {
    export class Victor {
        /**
         *  A string containing the lib version.
         */
        static version: string;

        /**
         * A string containing the lib short version.
         */
        static shortVersion: string;

        /**
         * Constructor for MyObject.
         * @param data The data to be used.
         */
        constructor(data: string);

        /**
         * Create a instance of Victor with data loaded from a file.
         * @param filename The name of the file to load data from.
         * @returns Returns a instance of the Victor class.
         */
        static load(filename: string): Victor;

        /**
         * Returns a message.
         * @returns A string containing the message.
         */
        test(msg: string): string;
        insert(id: number, vector: any, dimensions: number): void;
        delete(id: number): void;
        search(vector: any, dimensions: number): any;
        searchN(vector: any, dimensions: number, n: number): any;

        /**
         * Checks whether a given vector ID exists in the index.
         *
         * This function verifies the presence of a vector with the specified ID
         * within the index's internal map structure.
         *
         * @param index - Pointer to the index instance.
         * @param id - The unique vector ID to check.         *
         * @return true if the ID is found, false if not, or the index is NULL.
         * @throws Error if the index is invalid or if the ID cannot be checked.
         * 
         */
        contains(id: number): boolean;

        /**
         * Retrieves the internal statistics of the index.
         *
         * This function copies the internal timing and operation statistics
         * (insert, delete, search, search_n) into the provided `IndexStats` structure.
         *
         * @param index - Pointer to the index instance.
         * @return statistics.
         * @throws Error if the index is invalid or if the statistics cannot be retrieved.
         * 
         */
        stats(): any;

        /**
         * Retrieves the current number of elements in the index.
         *
         * This function returns the number of vector entries currently stored
         * in the index, regardless of their internal structure or state.
         *
         * @param index - Pointer to the index instance.
         * @return size of the index.
         * @throws Error if the index is invalid or if the size cannot be determined.
         * 
         */
        size(): number;

        /**
         * Update Index Context 
         * 
         * This function updates the context of the index.
         * The context can be used to store additional information or metadata related to the index.
         * 
         * @param index - Pointer to the index instance.
         * @param context - The new context to be set for the index.
         * @throws Error if the index is invalid or if the context cannot be updated.
         * 
         */
        updateContext(context: any): void;

        /**
         * Dumps the current index state to a file on disk.
         *
         * This function serializes the internal structure and data of the index,
         * including vectors, metadata, and any algorithm-specific state (e.g., graph links).
         * The resulting file can later be used to restore the index via a corresponding load operation.
         *
         * @param index - Pointer to the index instance.
         * @param filename - Path to the output file where the index will be saved.
         * @throws Error if the index is invalid or if the file cannot be written.
         *
         */
        dump(filename: string): void;
    }
}