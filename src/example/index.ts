import 'tsconfig-paths/register'; // To enable path aliasing. Not needed if you are using from node_modules.
import Victor from 'libvictor';

const victor = new Victor("Victor");
victor.test('Pelaca');

const victor2 = Victor.load('Victor from file');
victor2.test('JP');

const version = Victor.version;
const shortVersion = Victor.shortVersion;
console.log('\n', version, '\n', shortVersion);